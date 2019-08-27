///tested on cf http://codeforces.com/gym/101485/attachments problem E

#include <bits/stdc++.h>
using namespace std;
const int _MX=10011;
const int _inf = 1<<28;
int _n,_m;
/// n is number of node in L m is number of node in R
/// nodes in L numbered from 1 to n
///nodes in R numbered from n+1 to n+m
///0 is the dummy node
vector<int> _adj[_MX];
int _match[_MX],_lev[_MX];
bool bfs()
{
    int i,l,u,v;
    queue<int> q;
    for(i=1;i<=_n;i++)
    {
        if(!_match[i])_lev[i]=0,q.push(i);
        else _lev[i]=_inf;
    }
    _lev[0]=_inf;
    while(!q.empty())
    {
        u=q.front();q.pop();
        l=(int)_adj[u].size();
        for(i=0;i<l;i++)
        {
            v=_match[_adj[u][i]];
            if(_lev[v]==_inf)
            {
                _lev[v]=_lev[u]+1;
                q.push(v);
            }
        }
    }
    return _lev[0]!=_inf;
}

int dfs(int u)
{
    if(!u) return 1;
    int i,v,l=(int)_adj[u].size(),nxt;
    for(i=0;i<l;i++)
    {
        v=_adj[u][i];
        nxt=_match[v];
        if(_lev[u]+1==_lev[nxt])
        {
            if(dfs(nxt))
            {
                _match[u]=v;
                _match[v]=u;
                return 1;
            }
        }

    }
    _lev[u]=_inf;
    return 0;
}
vector<int> koing(){
    
    /**
     * Return a optimal set of verticies to cover the graph (vertex cover)
    */
	queue<int> q;
	vector<bool> vis(_n+_m+1,0);
	set<int> S;
	for(int i=1;i<=_n;i++){
		if(_match[i]==0){
			q.push(i);
			vis[i]=1;
			S.emplace(i);
		}
	}
	while(not q.empty()){
		int u=q.front();q.pop();
		for(int v : _adj[u]){
			S.insert(v);
			if(_match[v] and not vis[_match[v]]){
				S.insert(_match[v]);
				q.push(_match[v]);
				vis[_match[v]]=1;
			}
		}
	}
	vector<int> v;
	for(int i=1;i<=_n;i++)
		if(not present(S, i))v.pb(i);
	for(int i=_n+1;i<=_n+_m;i++)
		if(present(S, i))v.pb(i);
	return v;
}

int hopcrop()
{
    int mx_match=0,i;
    memset(_match,0 , (_n+_m+5)*sizeof(_match[0]));
    while(bfs())
    {
        for(i=1;i<=_n;i++)
        {
            if(_match[i]==0 && dfs(i))mx_match++;
        }
    }
    return mx_match;
}

inline void clear(){for(int i=0;i<=_n+_m;i++)_adj[i].clear();}
inline void addEdge(int u,int v){_adj[u].push_back(v); _adj[v].push_back(u);}
#define sc scanf
#define pf printf
#define xx first
#define yy second
typedef pair<int,int> pii;
typedef long long ll;

void print()
{
    for(int i=1;i<=_n;i++)
    {
        if(_match[i])printf("%d < -- > %d\n",i,_match[i]);
    }
}

void test()
{
    _n=4,_m=5;
    addEdge(1,5);
    addEdge(1,6);
    addEdge(1,7);
    addEdge(1,8);

    addEdge(2,7);
    addEdge(2,8);

    addEdge(3,7);
    addEdge(3,6);
    addEdge(3,9);

    addEdge(4,7);

    printf("%d\n",hopcrop());
    print();



}

int main()
{
    test();

    return 0;
}