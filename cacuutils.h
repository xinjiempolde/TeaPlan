#ifndef CACUUTILS_H
#define CACUUTILS_H
typedef double angle;   // 定义角度
typedef double radiam;  // 定义弧度
typedef struct{
    double x;
    double y;
}coor;    // 定义坐标
class CacuUtils
{
public:
    CacuUtils();
    coor CacuCordinate(const coor &center, const coor &point, const radiam &angle);
    radiam AngleToRadiam(angle a);

private:
    const double PI = 3.1415926535898;
};

#endif // CACUUTILS_H
