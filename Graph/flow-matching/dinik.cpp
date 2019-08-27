#include <bits/stdc++.h>//dinic
using namespace std;
#define pb push_back
const int _MX=25011;
const int _MXE=1000099;
const int _inf=1<<28;
struct _edge{
    int u,v,c,f;
    _edge(){};
    _edge(int _u,int _v,int _c,int _f){u=_u,v=_v,c=_c,f=_f;}
}ALL[_MXE];
int _cur; ///cur =0 initially
vector<int> _adj[_MX];
int _lev[_MX];
int _p[_MX];
inline void addEdge(int u,int v,int c)
{
    ALL[_cur]=_edge(u,v,c,0);
    ALL[_cur+1]=_edge(v,u,0,0);
    _adj[u].pb(_cur);
    _adj[v].pb(_cur+1);
    _cur+=2;
    ///notice that ALL[x] and ALL[x^1] are the same edges in revered direction
}
int _n; ///n is number of node in graph
int _s,_t;
inline bool _bfs()
{
    int i,u,v,l,cf,j;
    //for(i=0;i<=_n;i++)_lev[i]=_inf;
    memset(_lev,-1,(_n+2)*sizeof _lev[0]);
    _lev[_s]=0;
    queue<int> q;
    q.push(_s);
    while(!q.empty())
    {
        u=q.front();q.pop();
        l=(int)_adj[u].size();
        for(i=0;i<l;i++)
        {
            j=_adj[u][i];
            v=ALL[j].v;
            cf=ALL[j].c-ALL[j].f;
            if(cf && _lev[v]==-1)
            {
                _lev[v]=_lev[u]+1;
                q.push(v);
            }
        }
    }
    return _lev[_t]!=-1;
}
int  _dfs(int u,int f)
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
        if(_lev[u]+1==_lev[v])
        {
            x=_dfs(v,min(f,cf));
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
int dinic()
{
    int x,f=0;
    while(_bfs())
    {
        memset(_p,0,(_n + 2)*sizeof (_p[0]));
        while((x=_dfs(_s,_inf)))f+=x;
    }
    return f;
}
void work()
{
    //set _n, where _n is number of node 
    _cur=0;
    for(int i=0;i<=_n;i++)_adj[i].clear();
}
