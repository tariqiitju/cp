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
	point 	operator/(double a)	{return point(x/a,y/a);}
	bool operator==(point a)	{return fabs(x-a.x)<EPS and fabs(y-a.y)<EPS;}
	double len(){return sqrt(x*x+y*y);}
	double dot(point a){return x*a.x + y*a.y;}
	bool operator <(const point &a)const{
		if(x == a.x)
			return y < a.y;
		return x < a.x;
	}
};
double dist(point a,point b){return (a-b).len();}
const double INF = 1e30;
pair<double,double> smallRect(vector<point>&p){//expect points in anti clock-wise order,assuming polygon has at least 3 vertex
	int n = (int)p.size();
    int l = 1, r = 1, u = 1;
    double area = INF, per = INF;
    for( int i = 0; i < n; i++) {
        point edge = (p[(i+1)%n]-p[i]) / dist(p[(i+1)%n], p[i]);
        while(edge.dot(p[r%n]-p[i]) < edge.dot(p[(r+1)%n]-p[i]))
            r++;
        while(u < r || edge*(p[u%n]-p[i]) < edge*(p[(u+1)%n]-p[i]))
            u++;
        while(l < u || edge.dot(p[l%n]-p[i]) > edge.dot(p[(l+1)%n]-p[i]))
            l++;
        double w = edge.dot(p[r%n]-p[i]) - edge.dot(p[l%n]-p[i]);
        double h = fabs(((p[i]-p[u%n])* (p[(i+1)%n]-p[u%n])) / dist(p[i], p[(i+1)%n]));
        area = min(area, w * h);
        per = min(per, (w + h)*2);
    }
    return {area,per};
}
double cross(point o, point a, point b) {
    return (a-o)*(b-o);
}
vector<point> convexHull(vector<point> p) {//anti-clock wise 
	int n = (int)p.size();
	vector<point> ch(n+1);
    sort(p.begin(), p.end());
    int i, m = 0, t;
    for(i = 0; i < n; i++) {
        while(m >= 2 && cross(ch[m-2], ch[m-1], p[i]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    for(i = n-1, t = m+1; i >= 0; i--) {
        while(m >= t && cross(ch[m-2], ch[m-1], p[i]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    ch.resize(m-1);
    return ch;
}
int main(){
	int n,case_no=0;while(cin>>n and n){
	vector<point> p(n);for(int i=0;i<n;i++)cin>>p[i].x>>p[i].y;
	p = convexHull(p);
	pair<double,double> res = smallRect(p);
	cout<<setprecision(2)<<fixed<<res.first<<" "<<res.second<<endl;
}}
