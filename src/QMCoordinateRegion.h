/*****************************************************************************
 * QMCoordinateSpan.h
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

#ifndef QMCOORDINATEREGION_H
#define QMCOORDINATEREGION_H

#include "QMCoordinate.h"
#include "QMCoordinateSpan.h"

class QMCoordinateRegion
{
public:
    QMCoordinateRegion();
    QMCoordinateRegion(const QMCoordinate &southWest, const QMCoordinate &northEast);
    QMCoordinateRegion(qreal north, qreal south, qreal east, qreal west);
    QMCoordinateRegion(const QMCoordinate &center, const QMCoordinateSpan &span);

    bool contains(const QMCoordinate &point, bool proper = false) const;
    bool intersects(const QMCoordinateRegion &region) const;
    bool isEmpty() const;

    void extend(const QMCoordinate &point);
    void unite(const QMCoordinateRegion &region);

    qreal east() const;
    qreal west() const;
    qreal north() const;
    qreal south() const;

    void setEast(qreal east);
    void setWest(qreal west);
    void setNorth(qreal north);
    void setSouth(qreal south);

    QMCoordinate southWest() const;
    QMCoordinate northEast() const;
    QMCoordinate southEast() const;
    QMCoordinate northWest() const;

    QMCoordinate center() const;
    QMCoordinateSpan span() const;

    bool operator==(const QMCoordinateRegion &other);

private:
    qreal m_east;
    qreal m_west;
    qreal m_north;
    qreal m_south;
};

#endif // QMCOORDINATEREGION_H
