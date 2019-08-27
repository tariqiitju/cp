
int d[MX],low[MX],Time,artp[MX];///articulation point/bridge
void arDFS(int u,int par=-1){//d[u] is 0 initially
	d[u]=low[u]=Time++;
	int ch=0;
	for(int v : adj[u]){
		if(d[u]){
			if(par != v)low[u]=min(low[u],d[v]);
		}else{
			ch++;
			arDFS(v,u);
			low[u]=min(low[u],low[v]);
			if(par != -1 and low[v] >= d[u]){
				artp[u]=1;
				if(low[v] > d[u]){
					///bridge condition
				}
			}else if(low[v] > d[u]){
				///bridge condition
			}
		}
	}
	if(par==-1 and ch>1)artp[u]=1;
}
