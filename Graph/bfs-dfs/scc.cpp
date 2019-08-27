int compNumber[MX],com;
vector<int> component[MX],radj[MX];
void sccdfs(int u){
	compNumber[u]=com;
	vis[u]=1;
	component[com].push_back(u);
	for(int v : radj[u]){
		if(not vis[v])
			sccdfs(v);
	}
}
void scc(int n){
	memset(vis,0,(n+1)*sizeof(vis[0]));
	sortedNodes.clear();
	for(int i=1;i<=n;i++)
		if(not vis[i])tsort(i);
	memset(vis,0,(n+1)*sizeof(vis[0]));
	com=0;
	for(int i=n-1;i>=0;i--){
		int u=sortedNodes[i];
		if(not vis[u]){
			sccdfs(u);
			com++;
		}
	}
}
