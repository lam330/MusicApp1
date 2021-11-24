#include "audiofile.h"

AudioFile::AudioFile(QObject *parent) : QObject(parent)
{

}

AudioFile::AudioFile(const QString &name) : m_name(name)
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

QUrl AudioFile::convertToUrl(const QFileInfo &var)
{
    //convert filtPath to url => //C:/Users/ADMIN/Desktop/lamle/MusicApp/MusicApp
    QUrl url = QUrl(var.filePath());
    QUrl baseUrl = QUrl("file:///C:/Users/ADMIN/Desktop/lamle/MusicApp/MusicApp/music/");
    return baseUrl.resolved(url);
}







