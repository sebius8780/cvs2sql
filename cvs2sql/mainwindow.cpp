#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_mBrowseButton_clicked()
{
   QString fileName = QFileDialog::getOpenFileName(this, tr("Open csv"), QString(), tr("Excel CSV (*.csv)"));

   QStringList header;
   QFile f1(fileName);
   f1.open(QIODevice::ReadOnly);
   QTextStream s1(&f1);
   //while (!s1.atEnd())
   {
     QString s = s1.readLine(); // reads first line
     header = s.split(";"); // appends first column to list, ',' is separator
   }
   for (int i = 0; i < header.length(); i++){
    ui->mLogsText->insertPlainText(header[i] + "\n");
   }
   f1.close();
}
