int w[5005][5005],r[5005][5005],t[5005][5005];
void floyedWarshal(int n){
	for(int i=1;i <= n;i++){
		for(int j=1;j <= n; j++)
			r[i][j] = w[i][j],
			t[i][j] = j;
	}
	for(int c=1;c <= n; c++){
		for(int i=1;i <= n;i++){
			for(int j=1;j <= n;j++){
				if(r[i][c] + r[c][j] < r[i][j]){
					r[i][j] = r[i][c] + r[c][j];
					t[i][j] = t[i][c];
				}
			}
		}
	}
}
vector<int> findPath(int u,int v){
	vector<int> path={u};
	while(u!=v){
		u=t[u][v];
		path.push_back(u);
	}
	return path;
}
