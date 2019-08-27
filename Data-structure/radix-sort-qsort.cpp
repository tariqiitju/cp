//***************** FAST SORTING
#include <bits/stdc++.h>
using namespace std;
const int M = 2e6;
const int MBase = 1.1e6;
int __1[MBase+1],__2[M+1],__3[M+1];
template<class T> int * radixSort(T a[],int n,int base)
{
	///expected data type T = int,uint,long,ulong,int128,uint128,only non negative number
	///work better when maxvalue is small : closer to 10^9
	#define key(w)					(((w)/b)%base)
	T maxElement = *max_element(a,a+n);
	int *ord=__2,*tord=__3,*freq=__1;
	for(int i=0;i<n;i++)
		ord[i]=i;
	for(T b=1;1;b*=base){
		memset(freq,0,base*sizeof(freq[0]));
		for(int i=0;i<n;i++)
			freq[key(a[i])]++;
		for(int i=1;i<base;i++)
			freq[i]+=freq[i-1];
		for(int i=n-1;i>=0;i--)
			tord[--freq[key(a[ord[i]])]]=ord[i];
		swap(ord,tord);
		if(maxElement/b < base)break;
	}
	return ord;
}
template<class T>int com (const void * a, const void * b){
	  return ( *(T*)a - *(T*)b );
}
template<class T> void  quick_sort(T *a,int n){
	qsort(a,n,sizeof(a[0]),com<T>);
}
