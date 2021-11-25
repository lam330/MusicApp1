#include "cppsignalsender.h"

CppSignalSender::CppSignalSender(QObject *parent) : QObject(parent),
    mTimer(new QTimer(this)),
    mIndex(0)
{
    loadData();
    connect(mTimer, &QTimer::timeout, [=]() {
        ++mIndex;
        emit cppTimer(QString::number(mIndex));
    });

    mTimer->start(2700);
}



void CppSignalSender::loadData()
{
    qDebug() << "imageFolderPath: " << imageFolderPath;
    QDir dirObj(imageFolderPath);

    for(const QFileInfo &var : dirObj.entryInfoList(QDir::AllDirs | QDir::Files |QDir::NoDotAndDotDot))
    {
        qDebug() << "image fileName: " << var.fileName();
        //can't use file path => //if relative is not a relative URL, this function will return relative directly
        QUrl imageFileUrl = convertToUrl(var.fileName());
        qDebug() << "image url: " << convertToUrl(var.fileName());
        mImageUrls.append(convertToUrl(var.fileName()));
    }

    qDebug() << "size image list: " << mImageUrls.size();
}

QUrl CppSignalSender::convertToUrl(const QString &filePath)
{
    QUrl url = QUrl(filePath);
    QUrl baseUrl = QUrl("file:///C:/Users/ADMIN/Desktop/MusicApp/MusicApp/images/");
    return baseUrl.resolved(url);
}

QUrl CppSignalSender::getImageUrl()
{
    return mImageUrls.at(mIndex);
}
