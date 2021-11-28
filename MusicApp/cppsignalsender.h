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
    void cppTimer(const int& value);

private:
    QTimer *mTimer;
    int mIndex;
    QString imageFolderName = "MusicApp/imagesForSlide";
    QList<QUrl> mImageUrls;
};

#endif // CPPSIGNALSENDER_H
