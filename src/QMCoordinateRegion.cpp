/*****************************************************************************
 * QMCoordinateRegion.cpp
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

#include "QMCoordinateRegion.h"
#include <QtDebug>

QMCoordinateRegion::QMCoordinateRegion()
    : m_east(0.0)
    , m_west(0.0)
    , m_north(0.0)
    , m_south(0.0)
{
}

QMCoordinateRegion::QMCoordinateRegion(const QMCoordinate &southWest, const QMCoordinate &northEast)
    : m_east(northEast.longitude())
    , m_west(southWest.longitude())
    , m_north(northEast.latitude())
    , m_south(southWest.latitude())
{
}

QMCoordinateRegion::QMCoordinateRegion(qreal north, qreal south, qreal east, qreal west)
    : m_east(east)
    , m_west(west)
    , m_north(north)
    , m_south(south)
{
}

QMCoordinateRegion::QMCoordinateRegion(const QMCoordinate &center, const QMCoordinateSpan &span)
    : m_east(center.longitude() + span.longitudeDelta() / 2)
    , m_west(center.longitude() - span.longitudeDelta() / 2)
    , m_north(center.latitude() + span.latitudeDelta() / 2)
    , m_south(center.latitude() - span.latitudeDelta() / 2)
{
}

bool QMCoordinateRegion::contains(const QMCoordinate &point, bool proper) const
{
    qreal lng = point.longitude();
    qreal lat = point.latitude();

    bool r = false;
    if (proper)
        r = lat > west() && lat < east() && lng > south() && lng < north();
    else
        r = lat >= west() && lat <= east() && lng >= south() && lng <= north();

    return r;
}

bool QMCoordinateRegion::intersects(const QMCoordinateRegion &region) const
{
    Q_UNUSED(region)
    qWarning("QMCoordinateRegion::intersects not implemented; false returned");
    return false;
}

bool QMCoordinateRegion::isEmpty() const
{
    return (east() == west()) || (north() == south());
}

qreal QMCoordinateRegion::east() const
{
    return m_east;
}

qreal QMCoordinateRegion::west() const
{
    return m_west;
}

qreal QMCoordinateRegion::north() const
{
    return m_north;
}

qreal QMCoordinateRegion::south() const
{
    return m_south;
}

void QMCoordinateRegion::setEast(qreal east)
{
    m_east = east;
}

void QMCoordinateRegion::setWest(qreal west)
{
    m_west = west;
}

void QMCoordinateRegion::setNorth(qreal north)
{
    m_north = north;
}

void QMCoordinateRegion::setSouth(qreal south)
{
    m_south = south;
}

QMCoordinate QMCoordinateRegion::southWest() const
{
    return QMCoordinate(south(), west());
}

QMCoordinate QMCoordinateRegion::northEast() const
{
    return QMCoordinate(north(), east());
}

QMCoordinate QMCoordinateRegion::southEast() const
{
    return QMCoordinate(south(), east());
}

QMCoordinate QMCoordinateRegion::northWest() const
{
    return QMCoordinate(north(), west());
}

QMCoordinate QMCoordinateRegion::center() const
{
    return QMCoordinate((north() + south()) / 2, (east() + west()) / 2);
}

QMCoordinateSpan QMCoordinateRegion::span() const
{
    return QMCoordinateSpan(north() - south(), east() - west());
}

bool QMCoordinateRegion::operator==(const QMCoordinateRegion &other)
{
    return (east() == other.east()) && (west() == other.west()) && (north() == other.north())
        && (south() == other.south());
}
