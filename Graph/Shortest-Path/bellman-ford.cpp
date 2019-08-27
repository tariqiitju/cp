int d[MX];
bool bellmanford(int source,int n,int m){
	memset(d,100,(n+1)*sizeof(d[0]));
    d[source]=0;
    for(int p=1;p<n;p++){
        for(int i=0;i<m;i++){
        	int u=edges[i].xx,v=edges[i].yy;
            if(d[ v ] > d[ u ] + weight[i]){
                d[v]=d[ u ] + weight[i];
            }
        }
    }
    for(int i=0;i < m;i++){
        if(d[ edges[i].yy ] > d[ edges[i].xx ] + weight[i])
            return 0;
    }
    return 1;
}
