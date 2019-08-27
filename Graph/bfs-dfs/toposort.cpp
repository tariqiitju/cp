vector<int> adj[MX],sortedNodes;
bool vis[MX];
void tsort(int u){//topological sorting
	vis[u]=1;
	for(int v: adj[u]){
		if(not vis[v])
			tsort(v);
	}
	sortedNodes.push_back(u);
}
void toposort(int n){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        if(not vis[i])
            tsort(i);
    reverse(sortedNodes.begin(),sortedNodes.end());
}