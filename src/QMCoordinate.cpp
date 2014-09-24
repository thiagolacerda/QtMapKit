/*****************************************************************************
 * QMCoordinate.cpp
 *
 * Created: 08/7 2013 by uranusjr
 *
 * Copyright 2013 uranusjr. All rights reserved.
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

#include "QMCoordinate.h"

QMCoordinate::QMCoordinate()
    : m_latitude(0.0)
    , m_longitude(0.0)
{
}

QMCoordinate::QMCoordinate(qreal latitude, qreal longitude)
    : m_latitude(latitude)
    , m_longitude(longitude)
{
}

qreal QMCoordinate::latitude() const
{
    return m_latitude;
}

void QMCoordinate::setLatitude(qreal latitude)
{
    m_latitude = latitude;
}

qreal QMCoordinate::longitude() const
{
    return m_longitude;
}

void QMCoordinate::setLongitude(qreal longitude)
{
    m_longitude = longitude;
}

bool QMCoordinate::operator==(const QMCoordinate& other)
{
    return (latitude() == other.latitude()) && (longitude() == other.longitude());
}
