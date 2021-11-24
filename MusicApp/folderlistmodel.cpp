#include "folderlistmodel.h"

FolderListModel::FolderListModel(QObject *parent) : QAbstractListModel(parent)
{
    //Load default list
    loadData(audioFolderPath);
}

//FolderListModel::FolderListModel()
//{

//}

FolderListModel::~FolderListModel()
{

}

void FolderListModel::loadData(const QString &path)
{
    QDir dirObj(path);


    for(const QFileInfo var : dirObj.entryList(QDir::AllDirs | QDir::Files |QDir::NoDotAndDotDot))
    {
        AudioFile *file = new AudioFile(AudioFile::convertToUrl(var.filePath()), var.fileName());
        qDebug() << "fileName: " << var.fileName();
        addFile(file);
    }
}

int FolderListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mAudioList.size();
}

QVariant FolderListModel::data(const QModelIndex &index, int role) const
{
    //Check the bounds
    if (index.row() < 0 || index.row() >= mAudioList.count()) {
        return QVariant();
    }

    //Valid index
    AudioFile *file = mAudioList.at(index.row());

    switch (role) {
    case UrlRole:
        return file->url();
    case NameRole:
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
    qDebug() << "url => name: " << url.toEncoded().split('/').at(11);
    QString splitedName = url.toEncoded().split('/').at(11);
    addFile(url, splitedName);

}

void FolderListModel::addFile()
{
    //AudioFile *file = new AudioFile(url, mame)
    //addFile(file)
}

void FolderListModel::addFile(const QUrl &url, const QString &name)
{
    const int index = mAudioList.size();
    beginInsertRows(QModelIndex(),index,index);
    AudioFile *file = new AudioFile(url, name);
    addFile(file);
    endInsertRows();
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
    if(index < 0 || index >= mAudioList.count()) {
        return QUrl();
    }
    return mAudioList.at(index)->url();
}

QString FolderListModel::getName(const int &index)
{
    if(index < 0 || index >= mAudioList.count()) {
        return QString();
    }
    return mAudioList.at(index)->name();
}
