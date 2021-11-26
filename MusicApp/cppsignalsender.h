#ifndef CPPSIGNALSENDER_H
#define CPPSIGNALSENDER_H

#include <QObject>
#include <QTimer>
#include <QDir>
#include <QFileInfo>
#include <QUrl>
#include <QDebug>

class CppSignalSender : public QObject
{
    Q_OBJECT
public:
    explicit CppSignalSender(QObject *parent = nullptr);
    void loadData();
    QUrl convertToUrl(const QString &fileName);

public slots:
    QUrl getImageUrl();

signals:
    void cppTimer(QString value);

private:
    QTimer *mTimer;
    int mIndex;
    QString imageFolderPath = "C:/Users/ADMIN/Desktop/MusicApp/MusicApp/images";
    QList<QUrl> mImageUrls;
};

#endif // CPPSIGNALSENDER_H
