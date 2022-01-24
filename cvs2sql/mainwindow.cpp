#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QTextCodec>
#include <QRegularExpression>

struct UnicodedStream : QTextStream
{
    using QTextStream::QTextStream;

    template<typename T>
    UnicodedStream& operator<<(T const& t)
    {
        return static_cast<UnicodedStream&>(static_cast<QTextStream&>(*this) << t);
    }

    UnicodedStream& operator<<(char const* ptr)
    {
        return static_cast<UnicodedStream&>(*this << QString(ptr));
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mOpProgress->setValue(0);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    m_comonTrad.insert("true", "Y");
    m_comonTrad.insert("false", "N");

    ui->sepEdit->setText(QString(m_sep));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillCustomEdit()
{
    QString tempFormat = "insert into (";

    QString fieldsName = "";
    QString values = "";

    int prefix = 'A';
    int suffix = '0';

    for (int i = 0; i < mCustomHeaders.length(); i++)
    {
        fieldsName += mCustomHeaders[i]->text();
        values += "'VALUE_" + QString(prefix) + QString(suffix) + "'";
        if (i < mCustomHeaders.length() - 1)
        {
            fieldsName += ", ";
            values += ", ";
        }
        suffix++;
        if (suffix > '9')
        {
            prefix++;
            suffix = '0';
        }
    }
    tempFormat += fieldsName;
    tempFormat += ") VALUES ( ";
    tempFormat += values + " )";
    ui->customEdit->setPlainText(tempFormat);
}


void MainWindow::on_mBrowseButton_clicked()
{
   QString fileName = QFileDialog::getOpenFileName(this, tr("Open csv"), QString(), tr("Excel CSV (*.csv)"));

   QList<QByteArray> header;
   mFile = new QFile(fileName);
   ui->mFilenameEdit->setText(fileName);
   mFile->open(QIODevice::ReadOnly | QIODevice::Text);
   mStream = new UnicodedStream(mFile);
   mStream->setCodec("UTF-8");
   {
     QByteArray s = mStream->readLine().toUtf8(); // reads first line
     if (mStream->atEnd() || s.isEmpty())
     {
        QMessageBox::critical(this, "reading error", "wrong file format ( bad endlines )");
        return;
     }
     header = s.split(m_sep); // appends first column to list, ',' is separator
   }
   if (header.length() <= 1)
   {
    ui->mLogsText->insertPlainText("Warning ! headers have only one itm ! \n");
   }
   ui->mLogsText->insertPlainText("csv headers : " + QString::fromUtf8(header.join(", ")) + "\n");
   QVBoxLayout* listWidgetLayout = new QVBoxLayout();
   QString curHeader;
   for (int i = 0; i < header.length(); i++){
       QHBoxLayout *layout = new QHBoxLayout();
       curHeader = (QString::fromUtf8(header[i].replace("\"", "").replace("\'", "")));
       layout->addWidget(new QLabel(curHeader));
       QLineEdit* cur = new QLineEdit(curHeader);
       layout->addWidget(cur);
       listWidgetLayout->addItem(layout);
       mCustomHeaders.push_back(cur);
   }

   QString tableName = fileName;
   int ind = fileName.lastIndexOf('/');
   tableName = fileName.mid(ind + 1);
   tableName.chop(4);
   ui->mtableNameEdit->setText(tableName);
   ui->mProcessButton->setEnabled(true);

   if (ui->mGenerateId->isChecked())
   {
       QHBoxLayout *layout = new QHBoxLayout();
       QString curHeader = tableName + "_id";
       layout->addWidget(new QLabel(curHeader));
       QLineEdit* cur = new QLineEdit(curHeader);
       layout->addWidget(cur);
       listWidgetLayout->addItem(layout);
       mCustomHeaders.push_back(cur);
   }

   ui->scrollArea->setLayout(listWidgetLayout);
   ui->scrollArea->show();
   ui->customEdit->hide();
}

void MainWindow::on_mProcessButton_clicked()
{
    ui->mProcessButton->setEnabled(false);
    ui->mBrowseButton->setEnabled(false);
    // rest of the file
    QList<QByteArray> line;
    // QThread
    ui->mCurrentOpeLabel->setText("Current operation : loading file ...");
    mStream->seek(0); // rewind
    mStream->readLine(); // read header line
    mStream->setCodec("UTF-8");
    while (!mStream->atEnd())
    {
      QByteArray s = mStream->readLine().toUtf8(); // reads first line
      line.push_front(s);
    }
    ui->mLogsText->insertPlainText("Number of lines : " + QString::number(line.length()) + "\n");

    QStringList sqlHeaders;
    QString customFormat;
    bool isRemoveDoubles = ui->checkBox_2->isChecked();
    bool isCustom = ui->scrollArea->isHidden();
    if (!isCustom)
    {
        for (int i = 0; i < mCustomHeaders.length(); ++i)
        {
            sqlHeaders.append(mCustomHeaders.at(i)->text());
        }
    }
    else
    {
         customFormat = ui->customEdit->toPlainText();
    }

    QString outFileName = ui->mFilenameEdit->text().append(".sql");
    QFile outFile(outFileName);
    outFile.open(QIODevice::WriteOnly | QIODevice::Text);
    UnicodedStream outStream(&outFile);
    outStream.setCodec("UTF-8");

    // write the output file
    ui->mCurrentOpeLabel->setText("Current operation : writing sql file ...");
    int rowLimit = ui->mLimitRowsEdit->text().toInt();
    if (rowLimit == -1)
        rowLimit = line.length();
    ui->mOpProgress->setValue(0);
    ui->mOpProgress->setRange(0, rowLimit + 1);
    QStringList trads = m_comonTrad.keys();
    QStringList lines;


    for (int i = 0; i < rowLimit; ++i)
    {
        QString r;
        for (int t = 0; t < trads.length(); ++t)
        {
            r = QString::fromUtf8(line[i]);
            r = r.replace(trads[t], m_comonTrad[trads[t]]);
            line[i] = r.toUtf8();
        }
        if (!isCustom)
        {
            outStream << "insert into " << ui->mtableNameEdit->text() << "(" << sqlHeaders.join(",") << ") VALUES ('"
                      <<  QString::fromUtf8(line[i].replace("\"", "").replace("\'", "\\'").replace("'", "\'").split(m_sep).join("','"));
            if (ui->mGenerateId->isChecked())
            {
                outStream << "', '000" + QString::number(i);
            }
            outStream << "');\n" ;
        }
        else
        {
            QList<QByteArray> data = line[i].split(m_sep);
            QString outputFormat = customFormat;

            QString finalItem;
            QString key;
            int prefix = 'A';
            int suffix = '0';
            for (int j = 0; j < data.length(); ++j)
            {
                finalItem = data[j].trimmed();
                finalItem = data[j].trimmed().replace("\"", "");
                if (finalItem.startsWith("'"))
                {
                    // crop
                    finalItem = finalItem.mid(1);
                    finalItem = finalItem.mid(0, finalItem.length() - 2);
                }
                finalItem = finalItem.replace("'", "''"); // escaping ' in strings
                if (finalItem == " " || finalItem.isEmpty())
                {
                    // in case of '' we remove them also
                    outputFormat = outputFormat.replace("'VALUE_" + QString(prefix) + QString(suffix) + "'", "null");
                    outputFormat = outputFormat.replace("VALUE_" + QString(prefix) + QString(suffix), "null");
                }
                else
                {
                    outputFormat = outputFormat.replace("VALUE_" + QString(prefix) + QString(suffix), finalItem);
                }
                suffix++;
                if (suffix > '9')
                {
                    prefix++;
                    suffix = '0';
                }
            }


            bool writeLine = true;

            if (isRemoveDoubles)
            {
                QByteArray item = outputFormat.toUtf8();
                if (lines.contains(item))
                {
                    writeLine = false;
                }
                lines.push_back(item);
            }


            if (writeLine)
            {
                outputFormat.replace("INDEX", "'000" + QString::number(i) + "'" );
                outStream << outputFormat.toUtf8()
                           <<  ";\n" ;
            }
        }
        ui->mOpProgress->setValue(i + 1);
        if ((i % 5000) == 0) outStream.flush(); // regularly flush
    }
    ui->mOpProgress->setValue(rowLimit + 1);
    outStream.flush();
    outFile.close();

    ui->mLogsText->insertPlainText("File written : " + outFileName);

    mFile->close();
    delete mFile;
    ui->mBrowseButton->setEnabled(true);
    ui->mProcessButton->setEnabled(true);
    ui->mFilenameEdit->setText("");
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1)
    {
        ui->customEdit->show();
        ui->scrollArea->hide();

        fillCustomEdit();

    }
    else
    {
        ui->customEdit->hide();
        ui->scrollArea->show();
    }
}

void MainWindow::on_sepEdit_textChanged(const QString &arg1)
{
    if (arg1.length() == 1)
    {
        m_sep = arg1.at(0).toLatin1();
    }
}

