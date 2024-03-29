/*
    radius of convexhull incircle
*/
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-9;
const double INF = 1e30;
int steps = 40;     //increase for better precision
int stepsx = 40;
struct pt {
    double x, y;
    pt(){}
};
struct line {
    double a, b, c;
};
double dist (double x, double y, line & l) {
    return abs (x * l.a + y * l.b + l.c);
}
double radius (double x, double y, vector <line> & l) {
    int n = (int) l.size ();
    double res = INF;
    for (int i = 0; i <n; ++ i)
        res = min (res, dist (x, y, l [i]));
    return res;
}
double y_radius (double x, vector <pt> & a, vector <line> & l) {
    int n = (int) a.size ();
    double ly = INF, ry = -INF;
    for (int i = 0; i <n; ++ i) {
        int x1 = a [i] .x, x2 = a [(i + 1)% n] .x, y1 = a [i] .y, y2 = a [(i + 1)% n] .y;
        if (x1 == x2) continue;
        if (x1> x2) swap (x1, x2), swap (y1, y2);
        if (x1 <= x + EPS && x-EPS <= x2) {
            double y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
            ly = min (ly, y);
            ry = max (ry, y);
        }
    }
    for (int sy = 0; sy <steps; ++ sy) {
        double diff = (ry - ly) / 3;
        double y1 = ly + diff, y2 = ry - diff;
        double f1 = radius (x, y1, l), f2 = radius (x, y2, l);
        if (f1 <f2)
            ly = y1;
        else
            ry = y2;
    }
    return radius (x, ly, l);
}
double convexHull_incircle(vector<pt> a){
    int n = (int)a.size();
    if(n<3) return 0;
    vector <line> l (n);
    for (int i = 0; i <n; ++ i) {
        l [i] .a = a [i] .y - a [(i + 1)% n] .y;
        l [i] .b = a [(i + 1)% n] .x - a [i] .x;
        double sq = sqrt (l [i] .a * l [i] .a + l [i] .b * l [i] .b);
        l [i] .a /= sq, l [i] .b /= sq;
        l [i] .c = - (l [i] .a * a [i] .x + l [i] .b * a [i] .y);
    }

    double lx = INF, rx = -INF;
    for (int i = 0; i <n; ++ i) {
        lx = min (lx, a [i] .x);
        rx = max (rx, a [i] .x);
    }

    for (int sx = 0; sx <stepsx; ++ sx) {
        double diff = (rx - lx) / 3;
        double x1 = lx + diff, x2 = rx - diff;
        double f1 = y_radius (x1, a, l), f2 = y_radius (x2, a, l);
        if (f1 <f2)
            lx = x1;
        else
            rx = x2;
    }

    double ans = y_radius (lx, a, l);
    return ans;
}
