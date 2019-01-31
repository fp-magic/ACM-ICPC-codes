#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-7;
const double INF = 1e20;
const double pi = acos(-1.0);
int dcmp(double x)
{
    if (fabs(x) < eps)
        return 0;
    return (x < 0 ? -1 : 1);
}
inline double sqr(double x) { return x * x; }
struct Point
{
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    void input() { scanf("%lf%lf", &x, &y); }
    void output() { printf("%.2f %.2f\n", x, y); }
    bool operator==(const Point &b) const
    {
        return (dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0);
    }
    bool operator<(const Point &b) const
    {
        return (dcmp(x - b.x) == 0 ? dcmp(y - b.y) < 0 : x < b.x);
    }
    Point operator+(const Point &b) const
    {
        return Point(x + b.x, y + b.y);
    }
    Point operator-(const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    Point operator*(double a)
    {
        return Point(x * a, y * a);
    }
    Point operator/(double a)
    {
        return Point(x / a, y / a);
    }
};
double cross(Point a, Point b)
{ //叉积
    return a.x * b.y - a.y * b.x;
}
double dot(Point a, Point b)
{ //点积
    return a.x * b.x + a.y * b.y;
}
double rad(Point a, Point b)
{ //两个向量的夹⻆
    return fabs(atan2(fabs(cross(a, b)), dot(a, b)));
}
bool parallel(Point a, Point b)
{ //向量平⾏
    double p = rad(a, b);
    return dcmp(p) == 0 || dcmp(p - pi) == 0;
}

struct Line
{
    Point s, e; //直线的两个点
    double k;   //极⻆ 范围[-pi,pi]
    Line() {}
    Line(Point _s, Point _e)
    {
        s = _s, e = _e;
        k = atan2(e.y - s.y, e.x - s.x);
    }
    void input()
    {
        s.input();
        e.input();
    }
    void output()
    {
        printf("%.2f,%.2f %.2f,%.2f\n", s.x, s.y, e.x, e.y);
    }
    Point operator&(const Line &b) const
    { //直线的交点(保证存在)
        Point res = s;
        double t = (cross(s - b.s, b.s - b.e)) / cross(s - e, b.s - b.e);
        res.x += (e.x - s.x) * t;
        res.y += (e.y - s.y) * t;
        return res;
    }
};
bool parallel(Line a, Line b)
{ //直线平⾏
    return parallel(a.e - a.s, b.e - b.s);
}
int seg_cross_seg(Line a, Line v)
{ //线段相交判断
    //2:规范相交 1:不规范相交 0:不相交
    int d1 = dcmp(cross(a.e - a.s, v.s - a.s));
    int d2 = dcmp(cross(a.e - a.s, v.e - a.s));
    int d3 = dcmp(cross(v.e - v.s, a.s - v.s));
    int d4 = dcmp(cross(v.e - v.s, a.e - v.s));
    if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
        return 2;
    return (d1 == 0 && dcmp(dot(v.s - a.s, v.s - a.e)) <= 0) ||
           (d2 == 0 && dcmp(dot(v.e - a.s, v.e - a.e)) <= 0) ||
           (d3 == 0 && dcmp(dot(a.s - v.s, a.s - v.e)) <= 0) ||
           (d4 == 0 && dcmp(dot(a.e - v.s, a.e - v.e)) <= 0);
}
bool point_on_seg(Point p, Line l)
{ //判断点在线段上
    return dcmp(cross(p - l.s, l.e - l.s)) == 0 &&
           dcmp(dot(p - l.s, p - l.e) <= 0);
    //如果忽略端点交点改成⼩于号就好了
}
Point line_intersection(Line a, Line v)
{ //直线交点
    //调⽤前确保有交点
    double a1 = cross(v.e - v.s, a.s - v.s);
    double a2 = cross(v.e - v.s, a.e - v.s);
    return Point((a.s.x * a2 - a.e.x * a1) / (a2 - a1), (a.s.y * a2 - a.e.y * a1) / (a2 - a1));
}
int seg_intersection(Line a, Line b, Point &p)
{ //求线段交点
    //0:没有交点 1:规范相交 2:⾮规范相交
    //调⽤前确包只有⼀个交点
    int rel = seg_cross_seg(a, b);
    if (rel == 0)
        return 0;
    int cnt = 0;
    if (rel == 1)
    {
        if (point_on_seg(a.e, b))
            p = a.e, cnt++;
        if (point_on_seg(a.s, b))
            p = a.s, cnt++;
        if (point_on_seg(b.e, a))
            p = b.e, cnt++;
        if (point_on_seg(b.s, a))
            p = b.s, cnt++;
        return 2;
    }
    p = line_intersection(a, b);
    return 1;
}
int main()
{
    int tt, i, j;
    double l, r, t, ans;
    Line a, b;
    Point k, u, v;
    scanf("%d", &tt);
    while (tt--)
    {
        a.input();
        b.input();
        if (seg_cross_seg(a, b) == 0)
            ans = 0;
        else if (parallel(a, b))
            ans = 0;
        else if (parallel(a, Line(Point(0, 0), Point(1, 0))) | parallel(b, Line(Point(0, 0), Point(1, 0))))
            ans = 0;
        else
        {
            seg_intersection(a, b, k);
            if (a.s.y > a.e.y)
                u = a.s;
            else
                u = a.e;
            if (b.s.y > b.e.y)
                v = b.s;
            else
                v = b.e;
            if ((dcmp(u.x - k.x) != 0) && (dcmp(v.x - k.x) != 0))
            {
                l = (u.y - k.y) / (u.x - k.x);
                r = (v.y - k.y) / (v.x - k.x);
                if (dcmp(l) == dcmp(r))
                {
                    if (dcmp(fabs(l) - fabs(r)) >= 0 && dcmp(fabs(u.x - k.x) - fabs(v.x - k.x)) >= 0)
                    {
                        ans = 0;
                    }
                    else if (dcmp(fabs(r) - fabs(l)) >= 0 && dcmp(fabs(v.x - k.x) - fabs(u.x - k.x)) >= 0)
                    {
                        ans = 0;
                    }
                    else
                    {
                        t = min(max(a.s.y, a.e.y), max(b.s.y, b.e.y));
                        seg_intersection(a, Line(Point(-10005, t), Point(10005, t)), v);
                        l = v.x;
                        seg_intersection(b, Line(Point(-10005, t), Point(10005, t)), v);
                        r = v.x;
                        ans = fabs(l - r) * fabs(t - k.y) / 2.0;
                    }
                }
                else
                {
                    t = min(max(a.s.y, a.e.y), max(b.s.y, b.e.y));
                    seg_intersection(a, Line(Point(-10005, t), Point(10005, t)), v);
                    l = v.x;
                    seg_intersection(b, Line(Point(-10005, t), Point(10005, t)), v);
                    r = v.x;
                    ans = fabs(l - r) * fabs(t - k.y) / 2.0;
                }
            }
            else
            {
                t = min(max(a.s.y, a.e.y), max(b.s.y, b.e.y));
                seg_intersection(a, Line(Point(-10005, t), Point(10005, t)), v);
                l = v.x;
                seg_intersection(b, Line(Point(-10005, t), Point(10005, t)), v);
                r = v.x;
                ans = fabs(l - r) * fabs(t - k.y) / 2.0;
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}