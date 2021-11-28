#include "folderlistmodel.h"

FolderListModel::FolderListModel(QObject *parent) : QAbstractListModel(parent)
{
    //Load default list
    loadData();
}

//FolderListModel::FolderListModel()
//{

//}

FolderListModel::~FolderListModel()
{

}

void FolderListModel::loadData()
{

    //get folder Url
    QFileInfo fileInfo(QDir::currentPath());
    QString rootUrl = fileInfo.absolutePath();
    QString audioFolderPath = rootUrl + "/" + audioFolderName;
    QDir dirObj (audioFolderPath);

    for(const QFileInfo &var : dirObj.entryInfoList(QDir::AllDirs | QDir::Files |QDir::NoDotAndDotDot))
    {
        qDebug() << "audio fileName: " << var.fileName();
        QString audioName = var.fileName();
        qDebug() << "audio url: " << AudioFile::convertToUrl(var.fileName());
        QUrl audioUrl = AudioFile::convertToUrl(var.fileName());

        AudioFile *file = new AudioFile(audioUrl, audioName);
        addFile(file);
    }

    qDebug() << "size image list: " << mAudioList.size();
}

void FolderListModel::loadFoundListData()
{
    //clear data
    mFoundList.clear();
    //loop in list after adding
    for(int i = 0; i < mAudioList.size(); i++)
    {
        if(mAudioList.at(i)->name().contains(qmlValue)) {
            mFoundList.append(mAudioList.at(i));
            qDebug() << "size of mFound: " << mFoundList.size();
        }
    }
}

int FolderListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    if(!qmlValue.isEmpty()) {
        return mFoundList.size();
    } else {
        return mAudioList.size();
    }
}

QVariant FolderListModel::data(const QModelIndex &index, int role) const
{
    //Check the bounds
    qDebug() << "mAudioList: " <<mAudioList.count();
    qDebug() << "mFoundList: " <<mFoundList.count();

    if(!qmlValue.isEmpty()) {
        if(index.row() < 0 || index.row() > mFoundList.count()) {
            return QVariant();
        }
    }

    if (index.row() < 0 || index.row() >= mAudioList.count()) {
        return QVariant();
    }

    //Valid index
    AudioFile *file = mAudioList.at(index.row());


    switch (role) {
    case UrlRole:
        if(!qmlValue.isEmpty()) {
            return mFoundList.at(index.row())->url();
        }
        return file->url();
    case NameRole:
        if(!qmlValue.isEmpty()) {
            return mFoundList.at(index.row())->name();
        }
        return file->name();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> FolderListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[UrlRole] = "fileUrl";
    roles[NameRole] = "fileName";
    return roles;
}

bool FolderListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    AudioFile *file = mAudioList.at(index.row());
    bool somethingChanged = false;

    switch (role) {
    case UrlRole:
    {
        if(file->name() != value.toString()) {
            file->setName(value.toString());
            somethingChanged = true;
        }
    }
        break;
    case NameRole:
    {
        if(file->url() != value.toUrl()) {
            file->setUrl(value.toUrl());
            somethingChanged = true;
        }
    }
    }

    if(somethingChanged) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    return false;
}

Qt::ItemFlags FolderListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid()) {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsEditable;
}

void FolderListModel::addFile(AudioFile *file)
{
    const int index = mAudioList.size();
    beginInsertRows(QModelIndex(),index,index);
    mAudioList.append(file);
    endInsertRows();
}

void FolderListModel::addFile(QUrl url)
{
    //Split from url => name
    qDebug() << url;
    //QUrl("file:///C:/Users/ADMIN/Desktop/MusicApp/MusicApp/addedFile/Buc-Thu-Tinh-Thu-Hai-Ho-Quynh-Huong.mp3")
    qDebug() << "url => name: " << url.toEncoded().split('/').at(10);
    QString splitedName = url.toEncoded().split('/').at(10);

    qDebug() << "url after encode: " << url;
    addFile(url, splitedName);

}

void FolderListModel::addFile()
{

}

void FolderListModel::addFile(const QUrl &url, const QString &name)
{ 
    AudioFile *file = new AudioFile(url, name);
    addFile(file);
}

void FolderListModel::removeFile(const int &index)
{
    beginRemoveRows(QModelIndex(), index, index);
    mAudioList.removeAt(index);
    endRemoveRows();
}

void FolderListModel::removeLastFile()
{
    removeFile(mAudioList.size() - 1);
}

int FolderListModel::count() const
{
    qDebug() << "count " ;
    return rowCount(QModelIndex());
}

QUrl FolderListModel::getUrl(const int &index)
{
    if(!qmlValue.isEmpty()) {
        return mFoundList.at(index)->url();
    }

    if(index < 0 || index >= mAudioList.count()) {
        return QUrl();
    }

    return mAudioList.at(index)->url();
}

QString FolderListModel::getName(const int &index)
{
    if(!qmlValue.isEmpty()) {
        return mFoundList.at(index)->name();
    }

    if(index < 0 || index >= mAudioList.count()) {
        return QString();
    }
    return mAudioList.at(index)->name();
}

void FolderListModel::getQmlValue(const QString &textFieldInput)
{
    qmlValue = textFieldInput;
    qDebug() << "qmlValue: " << qmlValue;
}

void FolderListModel::resetQmlModel()
{
    beginResetModel();
    //Reload data to mFindedList
    if(!qmlValue.isEmpty()) {
        loadFoundListData();
    }
    endResetModel();
}

QString FolderListModel::getLocationForDialog()
{
    qDebug() << "getLocationForDialog";
    QFileInfo fileInfo(QDir::currentPath());
    QString rootUrl = fileInfo.absolutePath();
    QString addedFilePath = rootUrl + "/MusicApp/addedFile";
    qDebug() << "addedFilePath: " << addedFilePath;
    return addedFilePath;
}
