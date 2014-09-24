/*****************************************************************************
 * QMMarker.h
 *
 * Created by Thiago de Barros Lacerda
 *
 * Copyright 2014 Thiago de Barros Lacerda. All rights reserved.
 *
 * This file may be distributed under the terms of GNU Public License version
 * 3 (GPL v3) as defined by the Free Software Foundation (FSF). A copy of the
 * license should have been included with this file, or the project in which
 * this file belongs to. You may also find the details of GPL v3 at:
 * http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * If you have any questions regarding the use of this file, feel free to
 * contact the author of this file, or the owner of the project in which
 * this file belongs to.
 *****************************************************************************/

#ifndef QMMARKER_H
#define QMMARKER_H

#include <QColor>
#include <QObject>
#include <QString>

class QMCoordinate;

class QMMarker : public QObject
{
    Q_OBJECT
public:
    enum Type {
        Default,
        BackwardClosedArrow,
        BackwardOpenArrow,
        Circle,
        ForwardClosedArrow,
        ForwardOpenArrow
    };

    Q_ENUMS(Type);

    QMMarker(const QString &id, const QMCoordinate &point);
    QMMarker(const QString &id, qreal latitude, qreal longitude);
    QMMarker(const QString &id, const QMCoordinate &point, Type type, const QColor &color,
        const QString &title);
    QMMarker(const QString &id, qreal latitude, qreal longitude, Type type, const QColor &color,
        const QString &title);

    Q_PROPERTY(QString id READ id)
    Q_PROPERTY(qreal latitude READ latitude)
    Q_PROPERTY(qreal longitude READ longitude)
    Q_PROPERTY(QString color READ color)
    Q_PROPERTY(Type type READ type)
    Q_PROPERTY(QString title READ title)

    QString id() const;
    qreal latitude() const;
    qreal longitude() const;
    QString color() const;
    Type type() const;
    QString title() const;

    void setColor(const QColor&);
    void setType(Type);
private:
    QString m_id;
    qreal m_latitude;
    qreal m_longitude;
    Type m_type;
    QColor m_color;
    QString m_title;
};

#endif // QMMARKER_H
