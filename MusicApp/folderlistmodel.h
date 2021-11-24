#ifndef FOLDERLISTMODEL_H
#define FOLDERLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include "audiofile.h"

class FolderListModel : public QAbstractListModel
{
    Q_OBJECT
    enum AudioFileRoles {
        UrlRole,
        NameRole
    };
public:
    explicit FolderListModel(QObject *parent = nullptr);
    //FolderListModel();
    ~FolderListModel();

    void loadData(const QString &path);

    //Read from QMl
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    //Set from QML
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex& index) const;

public slots:
    void addFile();
    void addFile(AudioFile *file);
    void addFile(QUrl url);
    void addFile(const QUrl &url, const QString &name);

    void removeFile(const int &index);
    void removeLastFile();

    int count() const;
    QUrl getUrl(const int& index);
    QString getName(const int& index);


signals:
private:
    QList<AudioFile*> mAudioList;
    QString audioFolderPath = "C:/Users/ADMIN/Desktop/MusicApp/MusicApp/music";
    // C:/Users/ADMIN/Desktop/lamle/MusicApp/MusicApp/music
//    QList<AudioFile*> mTempList;
//    QList<AudioFile*> mFindedList;
};

#endif // FOLDERLISTMODEL_H
