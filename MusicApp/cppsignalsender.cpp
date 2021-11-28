#include "cppsignalsender.h"

CppSignalSender::CppSignalSender(QObject *parent) : QObject(parent),
    mTimer(new QTimer(this)),
    mIndex(0)
{
    loadData();

    //random
    srand((unsigned) time(0));
    connect(mTimer, &QTimer::timeout, [&]() mutable  {
        mIndex = (rand() % 9) + 1;
        //qDebug() << "index c++ = " << mIndex;
        emit cppTimer(mIndex);
    });

    mTimer->start(2700);
}



void CppSignalSender::loadData()
{
    //get folder Url
    QFileInfo fileInfo(QDir::currentPath());
    QString rootUrl = fileInfo.absolutePath();
    QString imagesFolderPath = rootUrl + "/" + imageFolderName;
    QDir dirObj (imagesFolderPath);

    for(const QFileInfo &var : dirObj.entryInfoList(QDir::AllDirs | QDir::Files |QDir::NoDotAndDotDot))
    {
        QUrl imageFileUrl = convertToUrl(var.fileName()); 
        mImageUrls.append(convertToUrl(var.fileName()));
    }

    qDebug() << "size image list: " << mImageUrls.size();
}

QUrl CppSignalSender::convertToUrl(const QString &fileName)
{

    //get folder Url
    QFileInfo fileInfo(QDir::currentPath());
    QString rootUrl = fileInfo.absolutePath();
    qDebug() << "rootUrl in convert: " << rootUrl; //C:/Users/ADMIN/Desktop/MusicApp

    QString folderUrl = "file:///" + rootUrl + "/MusicApp/imagesForSlide/";
    QUrl url = QUrl(fileName);

    QUrl baseUrl = QUrl(folderUrl);
    qDebug() << "Image finalUrl: " << baseUrl.resolved(url).toString();
    return baseUrl.resolved(url);// "file:///C:/Users/ADMIN/Desktop/MusicApp/MusicApp/music/"

}

QUrl CppSignalSender::getImageUrl()
{
    //qDebug() << "ImageUrl: " <<mImageUrls.at(mIndex);
    return mImageUrls.at(mIndex);
}
