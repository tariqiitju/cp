//given n points, you have to find out the largest rectangle.triangle possible.
#include <bits/stdc++.h>
using namespace std;
#define xx         first
#define yy         second
#define LL         long long
#define PI         acos(-1.0)
typedef pair<LL, LL> point;

bool cw(const point &a, const point &b, const point &c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

vector<point> convexHull(vector<point> p) {
    int n = p.size();
    if (n <= 1)
        return p;
    sort(p.begin(), p.end());
    int cnt = 0;
    vector<point> q(n * 2);
    for (int i = 0; i < n; q[cnt++] = p[i++])
        for (; cnt >= 2 && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    for (int i = n - 2, t = cnt; i >= 0; q[cnt++] = p[i--])
        for (; cnt > t && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    q.resize(cnt - 1 - (q[0] == q[1]));
    return q;
}
//vector < point > vc, vp;
LL area(point p1, point p2, point p3){
    LL ret = (p1.xx*p2.yy + p2.xx*p3.yy + p3.xx*p1.yy) - (p1.yy*p2.xx + p2.yy*p3.xx + p3.yy*p1.xx);
    if(ret < 0) ret *= -1;
    return ret;
}
double enclosing_triangle_area(vector<point> vp){
	vector<point> vc;
    vc.clear();
    vc = convexHull(vp);
    LL f = 0;
    for(int i = 0; i < vc.size(); i++){
        int c = i, d = i + 1;
        for(int j = i+1; j < vc.size(); j++){
            while(c < j && area(vc[i], vc[j], vc[c]) <= area(vc[i], vc[j], vc[c+1])) c++;
            while(d < vc.size() - 1 && area(vc[i], vc[j], vc[d]) <= area(vc[i], vc[j], vc[d+1])) d++;
            f = max(f, area(vc[i], vc[j], vc[c]) + area(vc[i], vc[j], vc[d]));
        }
    }
    return f/2.0;
}

int main() {

}


