#include "audiofile.h"

AudioFile::AudioFile(QObject *parent) : QObject(parent)
{

}

AudioFile::AudioFile(const QUrl &url, const QString &name) : m_url(url), m_name(name)
{}

AudioFile::~AudioFile()
{}

const QUrl &AudioFile::url() const
{
    return m_url;
}

void AudioFile::setUrl(const QUrl &newUrl)
{
    m_url = newUrl;
}

const QString &AudioFile::name() const
{
    return m_name;
}

void AudioFile::setName(const QString &fileName)
{
    m_name = fileName;
}

QUrl AudioFile::convertToUrl(const QString &fileName)
{
    //get folder Url
    QFileInfo fileInfo(QDir::currentPath());
    QString rootUrl = fileInfo.absolutePath();
    qDebug() << "rootUrl in convert: " << rootUrl; //C:/Users/ADMIN/Desktop/MusicApp

    QString folderUrl = "file:///" + rootUrl + "/MusicApp/music/";
    QUrl url = QUrl(fileName);

    QUrl baseUrl = QUrl(folderUrl);
    qDebug() << "finalUrl: " << baseUrl.resolved(url).toString();
    return baseUrl.resolved(url);// "file:///C:/Users/ADMIN/Desktop/MusicApp/MusicApp/music/"
}







