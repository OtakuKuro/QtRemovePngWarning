#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QImage>
#include <QDebug>
#include <QFileDialog>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void modifyIterationPng(QFileInfo fileInfo);
signals:
    void startButtonClicked(QString path);
public slots:
    void slotFindPicture(QString str);
signals:

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;

    QString mPath;

    int picNum;
};

#endif // MAINWINDOW_H
