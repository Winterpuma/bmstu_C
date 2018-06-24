/*
 * This program takes 4 coordinates of 2 line segments and prints out
 * weather they croos or not.
*/

#include <stdio.h>

int intersection(double ax, double bx, double cx, double dx,
                 double ay, double by, double cy, double dy)
{
    double common;
    double rH, sH, r, s;

    if (((ax == cx) && (ay == cy)) || ((ax == dx) && (ay == dy)) ||
            ((bx == cx) && (by == cy)) || ((bx == dx) && (by == dy)))
        return 1;

    common = (bx - ax)*(dy - cy) - (by - ay)*(dx - cx);
    if (common == 0)
        return 0;

    rH = (ay - cy)*(dx - cx) - (ax - cx)*(dy - cy);
    sH = (ay - cy)*(bx - ax) - (ax - cx)*(by - ay);
    r = rH / common;
    s = sH / common;

    if (r >= 0 && r <= 1 && s >= 0 && s <= 1)
        return 1;
    else
        return 0;
}

int main()
{
    double ax, bx, cx, dx;
    double ay, by, cy, dy;

    printf("Input 1 segment coords(x1 y1 x2 y2): ");
    scanf("%lf%lf%lf%lf", &ax, &ay, &bx, &by);
    printf("Input 2 segment coords(x3 y3 x4 y4): ");
    scanf("%lf%lf%lf%lf", &cx, &cy, &dx, &dy);

    if (((ax == bx) && (ay == by)) || ((cx == dx) && (cy == dy)))
        printf("Not segments.");
    else if (intersection(ax, bx, cx, dx, ay, by, cy, dy))
        printf("Intersect.");
    else
        printf("Don't intersect.");
    return 0;
}
