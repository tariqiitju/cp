/**************** HLD *****************/
const int N=1e5+5;
int par[N+2],lev[N+2];
vector<int>adj[N+2];int sz[N+2];
int start[N+2],End[N+2],Tim,head[N+2];
void cals(int u,int p)
{
  par[u]=p;lev[u]=1 + lev[p];sz[u]=1;
  for(auto &v:adj[u])
  {
    if(v==p)continue;
    cals(v,u);
    sz[u]+=sz[v];
    if(sz[v]>sz[adj[u][0]])
      swap(v,adj[u][0]);
  }
}
void HLD(int u)
{
  start[u]=++Tim;///1 based mapping,Tim++ for 0 based maping
  for(auto v:adj[u])
  {
    if(v==par[u])continue;
    if(v==adj[u][0])head[v]=head[u];
    else head[v]=v;
    HLD(v,u);
  }
  //End[n]=Tim; if needed
}
int Hqry(int u,int lc)
{
  int ret=0;
  while(head[u]!=head[lc])
  {
    int v=head[u];
    //ret+=Sum(start[u])-Sum(start[v]-1);
    u=par[v];
  }
  //return ret+Sum(start[u])-Sum(start[lc]-1);
}
int lca(int u,int v){///And modify it to answer range query
	while(head[u]!=head[v]){
		if(lev[u]>lev[v]){
			///range start[head[u]] - start[u]
			u=par[head[u]];
		}else{
			///range start[head[v]] - start[v]
			v=par[head[v]];
		}
	}
	if(lev[u] > lev[v]){
		//range star[v] to start[u]
		return v;
	}else{
		//range start[u] to start[v];
		return u;
	}
}
int Path(int u,int v)
{
  int ret=0;int lc=lca(u,v);
  ret=Hqry(u,lc)+Hqry(v,lc);
  ret-=Hqry(lc,lc);return ret;
}
