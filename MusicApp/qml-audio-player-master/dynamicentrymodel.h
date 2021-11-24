#ifndef DYNAMICENTRYMODEL_H
#define DYNAMICENTRYMODEL_H

#include <QtCore>
#include <QtGui>
#include <QAbstractListModel>

class DynamicEntryModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    enum RoleNames {
        FileNameRole = Qt::UserRole
    };

    explicit DynamicEntryModel(QObject *parent = 0);
    ~DynamicEntryModel();

public: // interface QAbstractListModel
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    int count() const;
    void pathData(QString path);

signals:
    void countChanged(int arg);

protected: // interface QAbstractListModel
    virtual QHash<int, QByteArray> roleNames() const;
private:
    //QList<QColor> m_data;
    QList<QString> m_data2;
    QHash<int, QByteArray> m_roleNames;
    int m_count;
    QString pathFolder;
};

#endif // DYNAMICENTRYMODEL_H
