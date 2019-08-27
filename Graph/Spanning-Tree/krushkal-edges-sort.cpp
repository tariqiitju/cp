int par[MX];
int fpar(int u){
	return par[u] = u==par[u] ? u  : fpar(par[u]);
}
pii edges[MX];
int weight[MX];
int krushkal(int n,int m){
	int cost=0;
	for(int i=1;i<=n;i++)
		par[i]=i;
	vector<int> ord(m);
	for(int i=0;i < m; i++)
		ord[i]=i;
	sort(all(ord),[=](int x,int y){
		return weight[x] < weight[y];
	});
	for(int i=0,c=1;c < n and i < m;i++){
		int u=edges[ord[i]].xx,v=edges[ord[i]].yy;
		u=fpar(u);
		v=fpar(v);
		if(u!=v){
			cost+=weight[ ord[i] ];
			c++;
			par[u]=v;
		}
	}
	return cost;
}
