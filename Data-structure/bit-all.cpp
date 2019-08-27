#include <bits/stdc++.h>
using namespace std;
///	******			BIT[tested]		**********
const int M=1e5 + 2;
int bit[M],N;
inline void add(int i,int v){///a[i] = v + a[i]
	for(;i<=N;i+=(i&-i))
		bit[i]+=v;
}
inline int sum(int i){//=sum{a[j],1 <= j <=i}
	int s=0;
	for(;i;i^=(i&-i))
		s+=bit[i];
	return s;
}
inline int select(int k){//return smallest i such sum(i) >= k
	int h=0;
	for(int i=(1<<(int)floor(log2((N))));i;i>>=1){
		if(h + i > N)continue;
		if(bit[h+i]<k)
	         k-=bit[h+i] , h+=i;
	}
	return h+1;
}
/* Other range queries : Min / Max query with monotonic [only higher value : for max] 
														[only smaller value : for min] 
														update : use usual bit
*/
///FAST RANGE SUM QUERY WITH RANGE UPDATE[tested]
int tree[2][M];
inline void _add(int id,int i,int v){
	for(;i<=N;i+=(i&-i))
		tree[id][i]+=v;
}
inline int _sum(int id,int i){
	int s=0;
	for(;i;i^=(i&-i))
		s+=tree[id][i];
	return s;
}
inline int Sum(int i){
	return _sum(0,i)*i - _sum(1,i);
}
inline void update(int l,int r,int v){
	_add(0,l,v);
	_add(0,r+1,-v);
	_add(1,l,v*(l-1));
	_add(1,r+1,-v*r);
}
///LIS with BIT[tested]
typedef pair<int,int> pii;
pii A[M];
inline void clear(int n){memset(A,0,(n+1)*sizeof(A[0]));}
inline pii Q(int i){
	pii s={0,0};
	for(;i;i^=(i&-i))
		s=max(s,A[i]);//**
	return s;
}
inline pii lis(int *a,int *par,int n){///1 <= a[i] <= n
	clear(n);int cur=0,last;
	for(int i=1;i<=n;i++){
		int j=a[i];
		pii ret = Q(j-1);
		par[i] = ret.second;
		if(ret.first + 1 > cur)//**
			cur = ret.first + 1, last=i;//**
		pii v = {ret.first + 1, i};
		for(;j <= n ; j+=(j&-j))
			A[j]=max(A[j],v);//**
	}
	return {cur,last};

}
