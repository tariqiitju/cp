/*
calculate number of pair (u,v) such n-1-R<=dist(u,v)<=n-1-L
 */
#include <bits/stdc++.h>
using namespace std;
#define pf                  printf
#define sc                  scanf
#define pb                  push_back
#define eb                  emplace_back
#define present(c,x)        ((c).find(x) != (c).end())
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define endl                '\n'
#define SZ(v)               ((int) (v).size())
#define all(v)              (v).begin(), (v).end()
typedef long long           ll;
typedef long double         LD;
typedef unsigned long long  ull;
typedef pair<int,int>       pii;
const LD EPS =              1e-9;
const LD PI=                acos(-1.0);
const int MX=               6e5+5;
ll mod=                     1e9+7;

ll ans;
int sz[MX];
bool deleted[MX];
vector<int> adj[MX];
int size_cal(int u,int p){
	sz[u]=1;
	for(int v : adj[u]){
		if(v!=p && !deleted[v])
			sz[u]+=size_cal(v,u);
	}
	return sz[u];
}
int find_centroid(int u,int p,int x){
	for(int v : adj[u])
		if(v!=p && !deleted[v])
			if(sz[v]>=x)
				return find_centroid(v,u,x);
	return u;
}

const int M=1e5 + 2;
int bit[M],N;                //Be carefull with types to avoid overflow
inline void add(int i,int v){///a[i] = v + a[i]
    for(++i;i<=N;i+=(i&-i))
        bit[i]+=v;
}
inline int sum(int i){//=sum{a[j],1 <= j <=i}
    i++;int s=0;
    for(;i;i^=(i&-i))
        s+=bit[i];
    return s;
}

int n,L,R;

void count(int u,int p,int l){
    int e = n - 1 - L - l;
    int s = n - 1 - R - l;
    if(e>=0)ans+=sum(e) - sum(max(s-1,-1));
    for(int v : adj[u]){
        if(not deleted[v] and v!=p){
            count(v,u,l+1);
        }
    }
}
void submit(int u,int p,int l){
    add(l,1);
    for(int v : adj[u]){
        if(not deleted[v] and v!=p){
            submit(v,u,l+1);
        }
    }
}
void erase(int u,int p,int l){
    add(l,-1);
    for(int v : adj[u]){
        if(not deleted[v] and v!=p){
            erase(v,u,l+1);
        }
    }
}

void centroid(int u){
    size_cal(u,0);
    int cen = find_centroid(u,0,sz[u]/2);
    add(0,1);
    for(int v : adj[cen]){
        if(not deleted[v]){
            count(v,cen,1);
            submit(v,cen,1);
        }
    }
    erase(cen,0,0);
    deleted[cen] = 1;
    for(int v : adj[cen]){
        if(not deleted[v])
            centroid(v);
    }


}

int main()
{
    ifstream cin("awesome.in");
    int tc;cin>>tc;while(tc--){
        cin>>n>>L>>R;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            deleted[i]=0;
            bit[i]=0;
        }
        N = n;
        ans = 0;
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        centroid(1);
        cout<<ans<<endl;
    }
    return 0;
}

/**
                     Md. Tariqul Islam
                          IIT,JU
                      fb/tariqiitju
                    tarik.amtoly@gmail.com
*/