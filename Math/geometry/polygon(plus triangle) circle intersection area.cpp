/*
 *  Cover        :  Triangle-cirle intersection , polygon circle intersection
 *	Problem      :  Fukushima Nuclear Blast LightOJ - 1358 uva 11978
 *  Algorithm    :  ALGEBRAIC sum of triangle & circle's intersection, Binary Search.
 *  Complexity   :  O(BS*n)
 *  Author       :  Md. Tariqul Islam
 */
#include <bits/stdc++.h>
using namespace std;
#define SQ(a)       ((a)*(a))
const double pi=acos(-1);
const double EPS=1e-9;
double mysqrt(double x){if(x < 0.)  return 0;return sqrt(x);}
double myasin(double x){if(x < -1.) return -pi/2;if(x > 1.) return pi/2;return asin(x);}
double myacos(double x){if(x < -1.) return -pi;if(x > 1.)   return 0;return acos(x);}
struct point{
    double x,y;
    point(){}
    point(double _x,double _y){x=_x,y=_y;}
    double  dis2(){ return SQ(x)+SQ(y);   }
    double  dis(){  return mysqrt(dis2());  }
    void    norm(){ double d = dis();x/=d;y/=d;}
    point   unit(){ point ret = *this;  ret.norm(); return ret;}
    double  dot(point b){       return x*b.x + y*b.y;}
    double  cross(point b){     return x*b.y - y*b.x;}
    double angle(point b){  return myacos( unit().dot( b.unit() ) );    }
};
point operator+(point a,point b){       return point(a.x+b.x, a.y+b.y); }
point operator-(point a){           return point (-a.x, -a.y);      }
point operator-(point a,point b){       return point(a.x-b.x, a.y-b.y); }
double operator*(point a,point b){  return a.cross(b);          }
point operator*(double a,point b){  return point(a*b.x, a*b.y);     }
point operator*(point b,double a){  return point(a*b.x, a*b.y);     }
point operator/(point b,double a){  return point(b.x/a, b.y/a);     }
//typedef point point;
double triangleCircleCommonArea(point A, point B, double r){//two vector defines a triangle
    double a = A.dis();
    double b = B.dis();
    //both inside
    if(a <= r && b <= r){
        return 0.5*(A*B);
    }
    // solving vector equation: (A + (B-A)t).(A + (B-A)t) = r*r
    double c2 = (B-A).dis2();
    double c1 = A.dot(B-A);
    double c0 = A.dis2() - r*r;
    double D = c1*c1 - c2*c0;
    vector<double> vt;
    vt.clear();
    vt.push_back(0);
    vt.push_back(1);
    if(D >= 0.){
        double t = (-c1 - mysqrt(D)) / c2;
        if(0<=t && t<=1)
            vt.push_back(t);
 
        t = (-c1 + mysqrt(D)) / c2;
        if(0<=t && t<=1)
            vt.push_back(t);
    }
    //sort 't's
    sort(vt.begin(), vt.end());
    //no intersection, both outside
    if(vt.size()==2)
        return 0.5*A.angle(B)*r*r;
 
    //full intersection, both outside
    if(vt.size()==4){
        point A1 = A + (B-A)*vt[1];
        point B1 = A + (B-A)*vt[2];
        return 0.5*A1.angle(A)*r*r + 0.5*A1*B1 + 0.5*B1.angle(B)*r*r;
    }
 
    //size == 3
    //A inside, B outside
    if(a <= r){ // A
        point B1 = A + (B-A)*vt[1];
        return 0.5*A*B1 + 0.5*B1.angle(B)*r*r;
    }
    //B inside, A outside
    if(b <= r){ // A
        point A1 = A + (B-A)*vt[1];
        return 0.5*A1.angle(A)*r*r + 0.5*A1*B;
    }
    return 0;
}
double triangleCircleAlgebraicCommonArea(point A, point B, double r){   //positive if CCW, negative if CW
                                                                        //two vector defines a triangle
    double fcall;
    if(A*B < 0){
        fcall = triangleCircleCommonArea(B, A, r);
        return -fcall;
    }
    else{
        fcall = triangleCircleCommonArea(A, B, r);
        return fcall;
    }
}

double polygon_circle_intersection(vector<point> &p,point certer,double r){
    if(r < EPS)
        return 0;
    double ret = 0;
    int i,j,n=(int)p.size();
    for(i=0;i<n;i++){
        j=(i+1)%n;
        ret += triangleCircleAlgebraicCommonArea(p[i] - certer, p[j]-certer, r);
    }
    return fabs(ret);
}
double getarea(vector<point> &p){
    double sum=0;
    int i,n=(int)p.size();
    for (i=0;i<n;i++)
        sum+=p[i]*p[(i+1)%n];
    return fabs(sum)/2;
}

#define sc      scanf
int main(){
    int tc,ts=0;sc("%d",&tc);while(tc--){
        int n;
        sc("%d",&n);
        vector<point> a(n);
        for(int i=0;i<n;i++)sc("%lf %lf",&a[i].x,&a[i].y);
        double p;point c;sc("%lf%lf%lf",&c.x,&c.y,&p);p/=100.0;
        double l = 0,r = 2000.0,area = getarea(a);
        for(int _c=100;_c--;){
            double m = (l+r)/2;
            double inter = polygon_circle_intersection(a, c, m);
            if(inter/area >= p-EPS) r =m;
            else l=m;
        }
        printf("Case %d: %d\n",++ts,(int)(r+0.5));
    }
}