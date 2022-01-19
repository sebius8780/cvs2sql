#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QFile>
#include <QList>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_mBrowseButton_clicked();

    void on_mProcessButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QTextStream* mStream;
    QFile*       mFile;
    QList<QLineEdit*> mCustomHeaders;
    char m_sep = ';';
    QMap<QString, QString> m_comonTrad;
};
#endif // MAINWINDOW_H
