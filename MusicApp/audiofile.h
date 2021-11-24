#ifndef AUDIOFILE_H
#define AUDIOFILE_H

#include <QObject>
#include <QUrl>
#include <QString>
#include <QFileInfo>
#include <QDebug>

class AudioFile : public QObject
{
    Q_OBJECT
public:
    explicit AudioFile(QObject *parent = nullptr);
    AudioFile(const QString &name);
    AudioFile(const QUrl &url, const QString &name);
    virtual ~AudioFile();

    const QUrl &url() const;
    void setUrl(const QUrl &newUrl);

    const QString &name() const;
    void setName(const QString &fileName);

    static QUrl convertToUrl(const QFileInfo &var);

signals:


private:
    QUrl m_url;
    QString m_name;

};

#endif // AUDIOFILE_H