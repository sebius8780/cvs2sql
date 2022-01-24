/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *mBrowseButton;
    QLineEdit *mFilenameEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *sepEdit;
    QPushButton *mProcessButton;
    QLabel *mCurrentOpeLabel;
    QProgressBar *mOpProgress;
    QLabel *label_2;
    QTextEdit *mLogsText;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *mtableNameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *mLimitRowsEdit;
    QTextEdit *customEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QCheckBox *checkBox_2;
    QCheckBox *mGenerateId;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 924);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mBrowseButton = new QPushButton(centralwidget);
        mBrowseButton->setObjectName(QString::fromUtf8("mBrowseButton"));

        verticalLayout->addWidget(mBrowseButton);

        mFilenameEdit = new QLineEdit(centralwidget);
        mFilenameEdit->setObjectName(QString::fromUtf8("mFilenameEdit"));

        verticalLayout->addWidget(mFilenameEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(label_4);

        sepEdit = new QLineEdit(centralwidget);
        sepEdit->setObjectName(QString::fromUtf8("sepEdit"));
        sepEdit->setMaximumSize(QSize(100, 16777215));
        sepEdit->setMaxLength(1);

        horizontalLayout_3->addWidget(sepEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        mProcessButton = new QPushButton(centralwidget);
        mProcessButton->setObjectName(QString::fromUtf8("mProcessButton"));
        mProcessButton->setEnabled(false);

        verticalLayout->addWidget(mProcessButton);

        mCurrentOpeLabel = new QLabel(centralwidget);
        mCurrentOpeLabel->setObjectName(QString::fromUtf8("mCurrentOpeLabel"));

        verticalLayout->addWidget(mCurrentOpeLabel);

        mOpProgress = new QProgressBar(centralwidget);
        mOpProgress->setObjectName(QString::fromUtf8("mOpProgress"));
        mOpProgress->setValue(24);

        verticalLayout->addWidget(mOpProgress);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        mLogsText = new QTextEdit(centralwidget);
        mLogsText->setObjectName(QString::fromUtf8("mLogsText"));
        mLogsText->setReadOnly(true);

        verticalLayout->addWidget(mLogsText);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        mtableNameEdit = new QLineEdit(centralwidget);
        mtableNameEdit->setObjectName(QString::fromUtf8("mtableNameEdit"));

        horizontalLayout->addWidget(mtableNameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        mLimitRowsEdit = new QLineEdit(centralwidget);
        mLimitRowsEdit->setObjectName(QString::fromUtf8("mLimitRowsEdit"));

        horizontalLayout_2->addWidget(mLimitRowsEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        customEdit = new QTextEdit(centralwidget);
        customEdit->setObjectName(QString::fromUtf8("customEdit"));

        verticalLayout->addWidget(customEdit);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 766, 108));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        mGenerateId = new QCheckBox(centralwidget);
        mGenerateId->setObjectName(QString::fromUtf8("mGenerateId"));

        verticalLayout->addWidget(mGenerateId);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mBrowseButton->setText(QCoreApplication::translate("MainWindow", "browse", nullptr));
        mFilenameEdit->setText(QString());
        mFilenameEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "filename.csv", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Separator : ", nullptr));
        mProcessButton->setText(QCoreApplication::translate("MainWindow", "Process", nullptr));
        mCurrentOpeLabel->setText(QCoreApplication::translate("MainWindow", "Current Operation :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Logs :", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "table name :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Row size limit :", nullptr));
        mLimitRowsEdit->setText(QCoreApplication::translate("MainWindow", "-1", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "remove doubles", nullptr));
        mGenerateId->setText(QCoreApplication::translate("MainWindow", "Generate id ", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "use custom format", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
