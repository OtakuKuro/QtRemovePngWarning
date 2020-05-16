#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("PngWarningRemove");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //QString path = "D:\\Files\\Qt\\CoVision2\\Resource";

    //qDebug() << mPath;

    picNum = 0;

    emit startButtonClicked(mPath);
//    QDir dir(mPath);
//    if(!dir.exists())
//    {
//        qDebug() << mPath;
//        return;
//    }

//    ui->textBrowser->append("Please Wait...");

//    QFileInfo fileInfo(mPath);
//    modifyIterationPng(fileInfo);

//    ui->textBrowser->append("Completed");
}

//void MainWindow::modifyIterationPng(QFileInfo fileInfo)
//{
//    if(fileInfo.isDir())
//    {
//        QList<QFileInfo> *fileList = new QList<QFileInfo>
//                (QDir(fileInfo.filePath()).entryInfoList());

//        for(int i=2; i<fileList->count(); i++)
//        {
//            modifyIterationPng(fileList->at(i));
//        }
//    }
//    else if(fileInfo.isFile())
//    {
//        if(fileInfo.suffix() == "png")
//        {
//            qDebug() << fileInfo.filePath();
//            ui->textBrowser->append(fileInfo.filePath());
//            QImage image;
//            image.load(fileInfo.filePath());
//            image.save(fileInfo.filePath());
//        }
//    }
//}

void MainWindow::on_toolButton_clicked()
{
    QString directory =
            QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Open Path"), QDir::currentPath()));

    if(!directory.isEmpty())
    {
        mPath = directory;
        ui->lineEdit->setText(directory);
    }
}

void MainWindow::slotFindPicture(QString str)
{
    ui->textBrowser->append(str);
    picNum++;
    ui->label->setText("Number:" + QString::number(picNum));
}
