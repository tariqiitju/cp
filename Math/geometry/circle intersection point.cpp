
#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
typedef pair<double,double> point;
double dis(point p,point q){
    return sqrt((p.xx-q.xx)*(p.xx-q.xx)+(p.yy-q.yy)*(p.yy-q.yy));
}

pair<point,point> circle_circle_intersection(point p,double r, point q,double s){
	if(s>r)swap(r,s),swap(p,q);
	double m=dis(p,q);//assert(m+eps < r+s and m+s > r);
    double n=(r*r-s*s+m*m)/(2.0*m);
    double h=sqrt(r*r-n*n);
    point t,u,v;
    t.xx=p.xx+(n*(q.xx-p.xx))/m;
    t.yy=p.yy+(n*(q.yy-p.yy))/m;
    u.xx=t.xx+(h*(q.yy-p.yy))/m;
    u.yy=t.yy-(h*(q.xx-p.xx))/m;
    v.xx=t.xx-(h*(q.yy-p.yy))/m;
    v.yy=t.yy+(h*(q.xx-p.xx))/m;
    return {u,v};
}

int main()
{

}
