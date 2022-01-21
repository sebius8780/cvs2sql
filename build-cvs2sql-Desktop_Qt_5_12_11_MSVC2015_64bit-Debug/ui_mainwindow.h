/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *mFilenameEdit;
    QPushButton *mBrowseButton;
    QProgressBar *mOpProgress;
    QLabel *mCurrentOpeLabel;
    QTextEdit *mLogsText;
    QLabel *label_2;
    QPushButton *mProcessButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *mtableNameEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *mLimitRowsEdit;
    QCheckBox *checkBox;
    QTextEdit *customEdit;
    QCheckBox *mGenerateId;
    QCheckBox *checkBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 924);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mFilenameEdit = new QLineEdit(centralwidget);
        mFilenameEdit->setObjectName(QString::fromUtf8("mFilenameEdit"));
        mFilenameEdit->setGeometry(QRect(50, 30, 411, 25));
        mBrowseButton = new QPushButton(centralwidget);
        mBrowseButton->setObjectName(QString::fromUtf8("mBrowseButton"));
        mBrowseButton->setGeometry(QRect(480, 30, 89, 25));
        mOpProgress = new QProgressBar(centralwidget);
        mOpProgress->setObjectName(QString::fromUtf8("mOpProgress"));
        mOpProgress->setGeometry(QRect(50, 160, 511, 23));
        mOpProgress->setValue(24);
        mCurrentOpeLabel = new QLabel(centralwidget);
        mCurrentOpeLabel->setObjectName(QString::fromUtf8("mCurrentOpeLabel"));
        mCurrentOpeLabel->setGeometry(QRect(50, 130, 511, 17));
        mLogsText = new QTextEdit(centralwidget);
        mLogsText->setObjectName(QString::fromUtf8("mLogsText"));
        mLogsText->setGeometry(QRect(50, 210, 521, 111));
        mLogsText->setReadOnly(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 190, 67, 17));
        mProcessButton = new QPushButton(centralwidget);
        mProcessButton->setObjectName(QString::fromUtf8("mProcessButton"));
        mProcessButton->setEnabled(false);
        mProcessButton->setGeometry(QRect(50, 80, 89, 25));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 340, 521, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        mtableNameEdit = new QLineEdit(layoutWidget);
        mtableNameEdit->setObjectName(QString::fromUtf8("mtableNameEdit"));

        horizontalLayout->addWidget(mtableNameEdit);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(50, 430, 521, 351));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 519, 349));
        scrollArea->setWidget(scrollAreaWidgetContents);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 390, 521, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        mLimitRowsEdit = new QLineEdit(layoutWidget1);
        mLimitRowsEdit->setObjectName(QString::fromUtf8("mLimitRowsEdit"));

        horizontalLayout_2->addWidget(mLimitRowsEdit);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(50, 800, 151, 23));
        customEdit = new QTextEdit(centralwidget);
        customEdit->setObjectName(QString::fromUtf8("customEdit"));
        customEdit->setGeometry(QRect(40, 430, 541, 351));
        mGenerateId = new QCheckBox(centralwidget);
        mGenerateId->setObjectName(QString::fromUtf8("mGenerateId"));
        mGenerateId->setGeometry(QRect(240, 800, 111, 23));
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(380, 800, 141, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        mFilenameEdit->setText(QString());
        mFilenameEdit->setPlaceholderText(QApplication::translate("MainWindow", "filename.csv", nullptr));
        mBrowseButton->setText(QApplication::translate("MainWindow", "browse", nullptr));
        mCurrentOpeLabel->setText(QApplication::translate("MainWindow", "Current Operation :", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Logs :", nullptr));
        mProcessButton->setText(QApplication::translate("MainWindow", "Process", nullptr));
        label->setText(QApplication::translate("MainWindow", "table name :", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Row size limit :", nullptr));
        mLimitRowsEdit->setText(QApplication::translate("MainWindow", "-1", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "use custom format", nullptr));
        mGenerateId->setText(QApplication::translate("MainWindow", "Generate id ", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "remove doubles", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
