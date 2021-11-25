#include "folderlistmodelforimage.h"

FolderListModelForImage::FolderListModelForImage(QObject *parent)
    : QAbstractListModel(parent),
      mTimer(new QTimer(this)),
      mIndex(3)
{
    loadData();

    //random
    srand((unsigned) time(0));
    connect(mTimer, &QTimer::timeout, [&]() mutable  {
        mIndex = (rand() % 9) + 1;
        qDebug() << "index c++ = " << mIndex;
        emit cppTimer(mIndex);
    });

    mTimer->start(2700);
}

FolderListModelForImage::~FolderListModelForImage()
{

}

void FolderListModelForImage::loadData()
{
    QDir dirObj(imageFolderPath);
    for(const QFileInfo var : dirObj.entryList(QDir::AllDirs | QDir::Files |QDir::NoDotAndDotDot))
    {
        Image *file = new Image(Image::convertToUrl(var.filePath()));
        qDebug() << "fileName: " << var.fileName();
        mImageList.append(file);
    }
}

int FolderListModelForImage::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mImageList.size();
}

QVariant FolderListModelForImage::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    if(row < 0 || row >= mImageList.count()) {
        return QVariant();
    }

    switch(role) {
    case UrlRole:
        qDebug() << "Image url: " << mImageList.at(row)->url();
        return mImageList.at(row)->url();
    }

    return QVariant();
}

QHash<int, QByteArray> FolderListModelForImage::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[UrlRole] = "fileUrl";
    return roles;
}

QUrl FolderListModelForImage::getImageUrl()
{
    if(mIndex < 0 || mIndex >= mImageList.count()) {
        return QUrl();
    }
    return mImageList.at(mIndex)->url();
}



Image::Image(QObject *parent)
{

}

Image::Image(const QUrl &url) : m_url(url)
{

}

Image::~Image()
{

}

QUrl Image::convertToUrl(const QFileInfo &var)
{
    QUrl url = QUrl(var.filePath());
    QUrl baseUrl = QUrl("file:///C:/Users/ADMIN/Desktop/lamle/MusicApp/MusicApp/images/");
    return baseUrl.resolved(url);
}

const QUrl &Image::url() const
{
    return m_url;
}

void Image::setUrl(const QUrl &newUrl)
{
    m_url = newUrl;
}


