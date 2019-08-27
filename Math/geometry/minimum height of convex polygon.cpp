#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
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
double minFarPointFromEdges(vector<point> &p){
	//(n^2) solution
	int n = (int)p.size();
	double res = 1e15;
	for(int i=0;i<n;i++){
		int j = (i + 1) % n;
		double h = 0;
		for(int k = 0; k < n; k++){
			h = max(h,area(p[i],p[j],p[k]));
		}
		res = min(res,h/dist(p[i],p[j]));
	}
	return res;

}
/*
min{distance of farthest vertex from every edge}
*/
double minFarPointFromEdges(vector<point> &p){
	//(nlogn) solution using ternary search
	int n = (int)p.size();
	if(n<=2)return 0;
	double res = 1e15;
	for(int i=0;i<n;i++){
		int j = (i + 1) % n;
		int r = (i-1+n)%n,l=(j+1)%n;
		while( (r-l+n)%n > 2){
			int d = ((r-l+n)%n)/3;
			int m1 = (l+d)%n;
			int m2 = (r -  d + n)%n;
			if(area(p[i], p[j], p[m1]) > area(p[i], p[j], p[m2]))
				r = m2;
			else l = m1;
		}
		double h = max(area(p[i], p[j], p[l]),area(p[i], p[j], p[r]));
		if(l!=r) h = max(h,area(p[i], p[j], p[(l+1)%n]));
		res = min(res,h/dist(p[i],p[j]));
	}
	return res;

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
	int n,case_no=0;while(cin>>n and n){
	vector<Point> p(n);for(int i=0;i<n;i++)cin>>p[i].first>>p[i].second;
	p = convexHull(p);
	n = (int) p.size();
	vector<point> a(n);
	for(int i=0;i<n;i++)a[i] = point(p[i].first,p[i].second);
	cout<<"Case "<<++case_no<<": ";
	cout<<setprecision(2)<<fixed<<minFarPointFromEdges(a)+.00<<endl;
}}
