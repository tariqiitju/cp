struct node{
	int u,d;
	node(){}
	node(int Node,int Cost){u=Node,d=Cost;}
	bool operator <(const node & a) const{
		return d > a.d;
	}
};
vector<int> adj[MX],adj_cost[MX];
bool vis[MX];
int d[MX];
void djkastra(int source,int n){
	memset(d,100,(n+1)*sizeof(d[0]));
	memset(vis,0,(n+1)*sizeof(vis[0]));
	d[source]=0;
	priority_queue<node> q;
	q.push(node(source,0));
	par[source]=0;
	while(not q.empty()){
		int u=q.top().u;
		ll dw=q.top().d;
		q.pop();
		if(not vis[u]){
			vis[u]=1;
			for(int i=0;i<SZ(adj[u]);i++){
				int v=adj[u][i];
				int w=adj_cost[u][i];
				if(w + d[u] < d[v]){
					d[v]=w + d[u];
					par[v]=u;
					q.push(node(v,d[v]));
				}
			}
		}
	}
}
