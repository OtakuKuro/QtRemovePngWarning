#include "findpng.h"

FindPng::FindPng(QObject *parent) : QObject(parent)
{

}

void FindPng::startCheck(QString path)
{
    QDir dir(path);
    if(!dir.exists())
    {
        qDebug() << path;
        return;
    }

    QFileInfo fileInfo(path);
    modifyIterationPng(fileInfo);

    //ui->textBrowser->append("Completed");

    emit signalFindPicture("Completed");
}

void FindPng::modifyIterationPng(QFileInfo fileInfo)
{
    if(fileInfo.isDir())
    {
        QList<QFileInfo> *fileList = new QList<QFileInfo>
                (QDir(fileInfo.filePath()).entryInfoList());

        for(int i=2; i<fileList->count(); i++)
        {
            modifyIterationPng(fileList->at(i));
        }
    }
    else if(fileInfo.isFile())
    {
        if(fileInfo.suffix() == "png")
        {
            //qDebug() << fileInfo.filePath();
            emit signalFindPicture(fileInfo.filePath());
            QImage image;
            image.load(fileInfo.filePath());
            image.save(fileInfo.filePath());
        }
    }
}
