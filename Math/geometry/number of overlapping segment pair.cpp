/*
number of pair of segment who overlap with each other
overlap = they has infinite number of common point
*/
#include <bits/stdc++.h>
using namespace std;
#define xx         first
#define yy         second
#define mp         make_pair
#define LL         long long
struct segment {
    LL x1, y1, x2, y2, fl;
    void fix(){
        if(x1 > x2){
            swap(x1, x2);
            swap(y1, y2);
        }
        if(x1 == x2){
            fl = 1;
            swap(x1, y1);
            swap(x2, y2);
            if(x1 > x2)swap(x1, x2);
        }else fl = 0;
    }
    void in(){
        cin >> x1 >> y1 >> x2 >> y2;
        fix();
    }
} ar[100001];

bool operator<(segment a, segment b){
    if(a.fl && !b.fl)return false;
    if(!a.fl && b.fl)return true;
    LL slope_a = (a.y2 - a.y1) * (b.x2 - b.x1);
    LL slope_b = (b.y2 - b.y1) * (a.x2 - a.x1);
    LL inter_xa = a.y1 * (a.x1 - a.x2) - a.x1 * (a.y1 - a.y2);
    LL inter_xb = b.y1 * (b.x1 - b.x2) - b.x1 * (b.y1 - b.y2);
    inter_xa *= (b.x1 - b.x2); inter_xb *= (a.x1 - a.x2);
    if(slope_a < slope_b)return true;
    if(slope_a == slope_b && inter_xa < inter_xb)return true;
    return false;
}
bool isequal(segment a, segment b){
    if(a.fl != b.fl)return false;
    LL slope_a = (a.y2 - a.y1) * (b.x2 - b.x1);
    LL slope_b = (b.y2 - b.y1) * (a.x2 - a.x1);
    LL inter_xa = a.y1 * (a.x1 - a.x2) - a.x1 * (a.y1 - a.y2);
    LL inter_xb = b.y1 * (b.x1 - b.x2) - b.x1 * (b.y1 - b.y2);
    inter_xa *= (b.x1 - b.x2); inter_xb *= (a.x1 - a.x2);
    if(slope_a == slope_b && inter_xa == inter_xb)return true;
    return false;
}
pair < LL, LL > pp[200001];
LL go(int s, int e){
    LL cnt = 0, c = 0, ret = 0;
    for(int i = s; i <= e; i++){
        pp[c++] = mp(ar[i].x1, 1);
        pp[c++] = mp(ar[i].x2, -1);
    }
    sort(pp, pp + c);
    for(int i=0;i<c;i++){
        if(pp[i].yy == 1){
            ret += cnt;
            cnt++;
        }
        else cnt--;
    }
    return ret;
}

LL count_segment_overlap(vector<segment> &v){
    int n = v.size();
    for(int i=0;i<n;i++)
        ar[i] = v[i],ar[i].fix();
    sort(ar, ar + n);
    int c=0; LL f = 0;
    for(int i=0;i<n;i++){
        if(i == c)continue;
        if(isequal(ar[i], ar[i - 1]))continue;
        f += go(c, i - 1);
        c = i; 
    }
    f += go(c, n - 1);
    return f;
}
int main() {
    int ts=0,tc;scanf("%d",&tc);while(tc--){
        int n;scanf("%d",&n);
        vector<segment> v(n);
        for(int i=0;i<n;i++)
            scanf("%lld%lld%lld%lld",&v[i].x1,&v[i].y1,&v[i].x2,&v[i].y2);
        printf("Case %d: %lld\n",++ts,count_segment_overlap(v));

    }

}

