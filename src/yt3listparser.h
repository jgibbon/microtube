/* $BEGIN_LICENSE

This file is part of Minitube.
Copyright 2009, Flavio Tordini <flavio.tordini@gmail.com>
Copyright 2018, Michał Szczepaniak <m.szczepaniak.000@gmail.com>

Minitube is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Minitube is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Minitube.  If not, see <http://www.gnu.org/licenses/>.

$END_LICENSE */

#ifndef YT3LISTPARSER_H
#define YT3LISTPARSER_H

#include <QtCore>

class Video;

class YT3ListParser : public QObject {
public:
    YT3ListParser(const QByteArray &bytes);
    const QVector<Video *> &getVideos() { return videos; }
    const QString &getNextPageToken() { return nextPageToken; }

private:
    void parseItem(const QJsonObject &item);

    QVector<Video *> videos;
    QString nextPageToken;
};

#endif // YT3LISTPARSER_H
