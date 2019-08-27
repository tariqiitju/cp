void spfa(int source,int n){
	memset(d,100,(n+1)*sizeof(d[0]));
	memset(vis,0,(n+1)*sizeof(vis[0]));
	d[source]=0;par[source]=0;
	queue<int> q;
	q.push(source);
	vis[source]=1;
	while( not q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=0;i<SZ(adj[u]);i++){
			int v=adj[u][i];
			int w=adj_cost[u][i];
			if(w + d[u] < d[v]){
				d[v]=w + d[u];
				par[v]=u;
				q.push(v);
				vis[v]=1;
			}
		}

	}
}
