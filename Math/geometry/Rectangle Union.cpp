
#include <bits/stdc++.h>
using namespace std;
/** Union Of rectangle Area */ 
const int maxN = 30000*5;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(ar) ar.begin(), ar.end()
#define pb push_back
struct Edge {
    bool open;
    int x, yMin, yMax;
    Edge(int x, int y1, int y2, bool op) {
        this->x = x;
        yMin = y1, yMax = y2;
        open = op;
    }
    bool operator < (const Edge &e) const {
        return (x < e.x);
    }
};


int n, m, h[maxN << 1];
int sum[maxN << 5], counter[maxN << 5];
vector<Edge> edges;



// void print ( )
// {   int maxsize=ceil(log2(num));
//      maxsize=2*pow(2,maxsize)-1;

//    for(int i= 1 ; i<=maxsize ; i++ )
//           cout<<sum[i]<<" ";
    
//     cout<<endl;

// }

void update(int p, int l, int r, int yMin, int yMax, bool open) {

  if (h[r] < yMin || yMax < h[l]) return;
    int c = p << 1, mid = (l + r) >> 1;

    if (yMin <= h[l] && h[r] <= yMax) {         // ymin --- h[l] --- h[r] --- ymax
        counter[p] += open ? 1 : -1;
        if (counter[p]) sum[p] = h[r] - h[l];  //if there is a rectangle at that posn that is bw h[l] and h[r] we will add that to length
        else sum[p] = sum[c] + sum[c + 1];    // else we will just sumup of lengths above and beloew this region
        return;
    }

    if (l + 1 >= r) return;

    update(c, l, mid, yMin, yMax, open);
    update(c + 1, mid, r, yMin, yMax, open);

    if (counter[p]) sum[p] = h[r] - h[l];
    else sum[p] = sum[c] + sum[c + 1];



}

long long solve() {
                                // process height for horzntl. sweep line
    sort(h + 1, h + m + 1);    //  Sorting the hieght according to the y coordinates
    int k = 1;

    REP (i, 2, m) if (h[i] != h[k])  //  Deleting the same horizontal sweeplines
       h[++k] = h[i];                //     as they are redundant
           m = k;
         //num  = m;


    for (int i = 0, lm = maxN << 4; i < lm; i++) // This is the initialization step of segment tree
        sum[i] = 0, counter[i] = 0;



    long long area = 0LL;  //  Initializing the Area

    sort(all(edges));  // Sorting according to x coordinates for ver. swp line

    update(1, 1, m, edges[0].yMin, edges[0].yMax, edges[0].open);
   // print();

    for (int i = 1; i < edges.size(); i++) {
        area += sum[1] * (long long)(edges[i].x - edges[i - 1].x);
        update(1, 1, m, edges[i].yMin, edges[i].yMax, edges[i].open);
      //  print();
    }
    return area;



}

int main() {

    int tc,ts=0;cin>>tc;while(tc--){

    
      int n;
      cin>>n;
      int  x1, y1, x2, y2;
        edges.clear();
        m = 0;
        REP (i, 1, n) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            if(x1==x2 && y1>y2)swap(y1,y2);
            else if(y1==y2   && x1>x2)swap(x1,x2);

            edges.pb(Edge(x1, y1, y2, true));   // Inserting the Left edge
            edges.pb(Edge(x2, y1, y2, false));  // Inserting the Right Edge

            h[++m] = y1; // Inserting the Lower y Coordinate 1 based inddexiing
            h[++m] = y2; // Inserting the Upper y Coordinate

        }
        printf("Case %d: %lld\n", ++ts,solve());
    }

    return 0;
}
