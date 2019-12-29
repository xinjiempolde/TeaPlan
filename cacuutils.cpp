#include "cacuutils.h"
#include <math.h>
CacuUtils::CacuUtils()
{

}

coor CacuUtils::CacuCordinate(const coor &center, const coor &point, const angle &angle)
{
    coor after_point;
    radiam x = AngleToRadiam(angle);
    after_point.x = (point.x - center.x) * cos(x) - (point.y - center.y) * sin(x) + center.x;
    after_point.y = (point.y - center.y) * cos(x) + (point.x - center.x) * sin(x) + center.y;
    return after_point;
}

radiam CacuUtils::AngleToRadiam(angle a)
{
    return (a * PI) / 180;
}

