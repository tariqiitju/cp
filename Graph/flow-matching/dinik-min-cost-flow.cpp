#include <bits/stdc++.h>//dinic mincost flow
using namespace std;
#define pb push_back
const int _MX=25011;
const int _MXE=1000009;
const int _inf=1<<28;
struct edge{
    int u,v,c,g,f;
    edge(){};
    edge(int _u,int _v,int _c,int _g,int _f){u=_u,v=_v,c=_c,g=_g,f=_f;}
}ALL[_MXE];
int _cur; ///cur =0 initially
vector<int> _adj[_MX];
int _lev[_MX];
bool _vis[_MX];
int _p[_MX];
void addEdge(int u,int v,int c,int g)
{
    ALL[_cur]=edge(u,v,c,g,0);
    ALL[_cur+1]=edge(v,u,0,-g,0);
    _adj[u].pb(_cur);
    _adj[v].pb(_cur+1);
    _cur+=2;
    ///notice that ALL[x] and ALL[x^1] are the same edges in revered direction
}
int _n; ///n is number of node in graph
int _s,_t;
bool spfa()
{
    int i,u,v,l,cf,j;
    for(i=0;i<=_n;i++)_lev[i]=_inf;
    _lev[_s]=0;
    queue<int> q;
    q.push(_s);
    _vis[_s]=1;
    while(!q.empty())
    {
        u=q.front();q.pop();
        _vis[u]=0;
        l=(int)_adj[u].size();
        for(i=0;i<l;i++)
        {
            j=_adj[u][i];
            v=ALL[j].v;
            cf=ALL[j].c-ALL[j].f;
            if(cf && _lev[u]+ALL[j].g<_lev[v])
            {
                _lev[v]=_lev[u]+ALL[j].g;
                if(!_vis[v])
                {
                    q.push(v);
                    _vis[v]=1;
                    
                }
            }
        }
    }
    return _lev[_t]!=_inf;
}
int  dfs(int u,int f)
{
    if(!f) return 0;
    if(u==_t) return f;

    int l=(int)_adj[u].size(),i,j,v,cf,x;

    for(;_p[u]<l;_p[u]++)
    {
        i=_p[u];
        j=_adj[u][i];
        v=ALL[j].v;
        cf=ALL[j].c-ALL[j].f;
        if(_lev[u]+ALL[j].g==_lev[v])
        {
            x=dfs(v,min(f,cf));
            if(x)
            {
                ALL[j].f+=x;
                ALL[j^1].f-=x;
                return x;
            }
        }
    }
    return 0;
}
pair<int,int> dinic()
{
    int x,f=0;
    while(spfa())
    {
        memset(_p,0,(_n+5)*sizeof _p[0]);
        while((x=dfs(_s,_inf)))f+=x;
    }
    int cost=0;
    for(int i=0;i<_cur;i+=2)
    {
        if(ALL[i].f)cost+=ALL[i].f*ALL[i].g;
    }
    return make_pair(f,cost);
}
void work()
{
    //set _n, where _n is number of node 
    ///USE A VISITED ARRAY IN DFS IF  GRAPH IS UNDIRECTED!!!
    _cur=0;
    int i;

    for(i=0;i<=_n;i++)_adj[i].clear();
}
