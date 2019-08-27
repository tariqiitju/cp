///*************Iterative Segment Tree******
///********Point Update Range Query
const int M = 1e5 + 2;
int tree[M<<1];
void build(int *a,int n){//array is always 0 based
	for(int i=0;i<n;i++)
		tree[i+n]=a[i];
	for(int i=n-1;i;i--)
		tree[i]=tree[i<<1]+tree[i<<1|1];
}
void update(int i,int v,int n){
	for(tree[i+=n]=v;i>1;i>>=1){
		tree[i>>1]=tree[i]+tree[i^1];
	}
}
int sum(int l,int r,int n){
	int s=0;
	for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
		if(l&1)s+=tree[l++];
		if(r&1)s+=tree[--r];
	}
	return s;
}

//*********Range Update Point Query
void update(int l,int r,int v,int n){
	for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
		if(l&1)tree[l++]+=v;
		if(r&1)tree[--r]+=v;
	}
}
int query(int i,int n){
	int s=0;
	for(;i;i>>=1)
		s+=tree[i];
	return s;
}

