/*****************************************************************************
 * QMMarker.cpp
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

#include "QMMarker.h"

#include "QMCoordinate.h"

QMMarker::QMMarker(const QString &id, const QMCoordinate &point)
    : m_id(id)
    , m_latitude(point.latitude())
    , m_longitude(point.longitude())
    , m_type(Default)
    , m_color(QColor(Qt::white))
{ }

QMMarker::QMMarker(const QString &id, qreal latitude, qreal longitude)
    : m_id(id)
    , m_latitude(latitude)
    , m_longitude(longitude)
    , m_type(Default)
    , m_color(QColor(Qt::white))
{ }

QMMarker::QMMarker(const QString &id, const QMCoordinate &point, Type type, const QColor &color,
    const QString &title)
    : m_id(id)
    , m_latitude(point.latitude())
    , m_longitude(point.longitude())
    , m_type(type)
    , m_color(color)
    , m_title(title)
{ }

QMMarker::QMMarker(const QString &id, qreal latitude, qreal longitude, Type type,
    const QColor &color, const QString &title)
    : m_id(id)
    , m_latitude(latitude)
    , m_longitude(longitude)
    , m_type(type)
    , m_color(color)
    , m_title(title)
{ }

QString QMMarker::id() const
{
    return m_id;
}

qreal QMMarker::latitude() const
{
    return m_latitude;
}

qreal QMMarker::longitude() const
{
    return m_longitude;
}

QString QMMarker::color() const
{
    return m_color.name();
}

QMMarker::Type QMMarker::type() const
{
    return m_type;
}

QString QMMarker::title() const
{
    return m_title;
}

void QMMarker::setColor(const QColor &color)
{
    m_color = color;
}

void QMMarker::setType(QMMarker::Type type)
{
    m_type = type;
}
