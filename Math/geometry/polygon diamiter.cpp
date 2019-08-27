#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
struct point{
	double x,y;
	point(){x=y=0;}
	point(double _x,double _y){x=_x,y=_y;}
	point 	operator-()			{return point(-x,-y);}
	point 	operator-(point a)	{return point(x-a.x,y-a.y);}
	point 	operator+(point a)	{return point(x+a.x,y+a.y);}
	double 	operator*(point a)	{return (x*a.y-y*a.x);}
	bool operator==(point a)	{return fabs(x-a.x)<EPS and fabs(y-a.y)<EPS;}
	double len(){return sqrt(x*x+y*y);}
};
double area(point a,point b,point c){return fabs((b-a)*(c-a));}
double dist(point a,point b){return (a-b).len();}
double polygonDiameter(vector<point> &p)
{
    int n=(int)p.size();
    if(n<2) return 0;
    else if(n==2) return dist(p[0],p[1]);//distance between two points
    else
    {
        int i=n-1,j=0,k=1;
        double res=0;
        while(area(p[i], p[j], p[k+1]) > area(p[i],p[j],p[k]))
        	k++;
        i=0,j=k;
        while(i<=k && j<n)
        {
            res=max(dist(p[i],p[j]),res);
            while(j < n-1 and area(p[i],p[i+1],p[j+1]) > area(p[i],p[i+1],p[j]))
            {
                j++;
                res=max(dist(p[i],p[j]),res);
            }
            i++;
        }
        return res;
    }
}
typedef pair<long long,long long> Point;
bool cw(const Point &a, const Point &b, const Point &c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}
vector<Point> convexHull(vector<Point> p) {
    int n = p.size();
    if (n <= 1)
        return p;
    sort(p.begin(), p.end());
    int cnt = 0;
    vector<Point> q(n * 2);
    for (int i = 0; i < n; q[cnt++] = p[i++])
        for (; cnt >= 2 && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    for (int i = n - 2, t = cnt; i >= 0; q[cnt++] = p[i--])
        for (; cnt > t && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    q.resize(cnt - 1 - (q[0] == q[1]));
    return q;
}

int main(){
	int n;cin>>n;
	vector<Point> p(n);for(int i=0;i<n;i++)cin>>p[i].first>>p[i].second;
	
	p = convexHull(p);

	n = (int) p.size();
	vector<point> a(n);
	for(int i=0;i<n;i++)a[i] = point(p[i].first,p[i].second);
	cout<<setprecision(8)<<fixed<<polygonDiameter(a)<<endl;

}