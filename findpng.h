#ifndef FINDPNG_H
#define FINDPNG_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QImage>
#include <QDebug>
#include <QTime>

class FindPng : public QObject
{
    Q_OBJECT
public:
    explicit FindPng(QObject *parent = nullptr);
signals:
    void signalFindPicture(QString str);

public slots:
    void startCheck(QString path);
private:
    void modifyIterationPng(QFileInfo fileInfo);

};

#endif // FINDPNG_H
