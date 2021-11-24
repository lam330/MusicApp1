#include "dynamicentrymodel.h"
#include <QString>
#include <QFileInfo>

DynamicEntryModel::DynamicEntryModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_roleNames[FileNameRole] = "file";
    pathFolder = "C:/Users/ADMIN/Desktop/lamle/test3/test3/music";
    pathData(pathFolder);
}

DynamicEntryModel::~DynamicEntryModel()
{
}


int DynamicEntryModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << "rowCount";
    Q_UNUSED(parent);

    return m_data2.count();
}

QVariant DynamicEntryModel::data(const QModelIndex &index, int role) const
{
    qDebug() << "data " ;
    int row = index.row();

    if(row < 0 || row >= m_data2.count()) {
        return QVariant();
    }


    switch(role) {
    case FileNameRole:
        qDebug() << "fileName case: " << m_data2.at(row);
        return m_data2.at(row);
    }
    return QVariant();
}

int DynamicEntryModel::count() const
{
    qDebug() << "count " ;
    return rowCount(QModelIndex());
}

void DynamicEntryModel::pathData(QString path)
{
    QDir dirObj(path);
    for(const QFileInfo var : dirObj.entryList(QDir::AllDirs | QDir::Files |QDir::NoDotAndDotDot))
    {
        qDebug() << var.fileName();
        m_data2.append(var.fileName());
    }
}

QHash<int, QByteArray> DynamicEntryModel::roleNames() const
{
    qDebug() << "Hash " ;
    return m_roleNames;
}
