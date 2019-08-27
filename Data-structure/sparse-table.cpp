const int log_n=20;
const int N=1e5 + 10;
int t[log_n][N];
void build(int *a,int n){
	for(int i=0;i<n;i++)t[0][i]=a[i];
	for(int j=0;(1<<j)<=n;j++)
		for(int i=0;i + (1<<j) <= n;i++)
			t[j][i]=min(t[j-1][i],t[j-1][i + (1<<(j-1))]);
}
int query(int l,int r){
	int j=floor(log2(r-l+1));
	return min(t[j][l],t[j][r-(1<<j)+1]);
}
