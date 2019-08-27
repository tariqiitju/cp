#include <bits/stdc++.h>
using namespace std;
template<class _T>inline _T pow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans*=a,ans%=m;a*=a;a%=m;b>>=1;}return ans;}
template<class _T>inline _T add(_T a,_T b,_T m){return a>=m-b?a-(m-b):a+b;}//a,b<m
template<class _T>inline _T multiply(_T a,_T b,_T m){_T ans=0;if(b>a)swap(a,b);while(b){if(b&1)ans=add(ans,a,m);b>>=1;a=add(a,a,m);}return ans;}//a,b<m
template<class _T>inline _T bigpow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans=multiply(ans,a,m);a=multiply(a,a,m);b>>=1;}return ans;}
typedef long long ll;
typedef unsigned long long ull;
const int accuracy_factor=13;///reduce this to speedUP
template<class _T>inline bool MillerRabin(_T n)
{
	///determetestic till 64 bit : 13*log(n)*log(n)
	///expected to work with any number of bit (reffering ___int128)
	if(n==2 || n==3) return 1;
	if(n<2 || !(n&1)) return 0;
	_T a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41}; //13
	_T r=0;
	_T s=n-1;
	while(!(s&1))s>>=1,r++;
	for(int i=0;i<accuracy_factor && a[i]<n-1 ;i++)
	{
		_T x= bigpow(a[i],s,n);///try to use normal pow to boost
		if(x==1 || x==n-1) continue;
		bool composit=1;
		for(int k=0;k<r-1;k++)
		{
			x = multiply(x,x,n);///try to use normal multiplication to boost
			if(x==n-1){composit=0;break;}
			if(x==1)return 0; ///Found a non-Trivial sqrt of unity modulo n
		}
		if(composit)return 0;///failed fermat test
	}
	return 1;
}
const int INERATION_LIMIT=1<<16; ///fourth root of maximum input
template<class _T>inline _T pho(_T n,_T x){
	_T y=x,d=1;
	_T one=1;
	for(int cnt=INERATION_LIMIT;cnt-- and d==1;){
		x=add(multiply(x,x,n),one,n);///try to use normal multiplication to boost
		y=add(multiply(y,y,n),one,n);
		y=add(multiply(y,y,n),one,n);
		d=__gcd(x>y?x-y:y-x,n);
	}
	return d;
}
template<class _T>inline vector<_T> fastFactorize(_T n){
	///expected to work for any size of input positive int
	///with compexity fouth_root(n)*log(n)*log(n) //2^24 for n=n^64 
	///expected to run a lot faster in general
	_T a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41}; //13
	queue<_T> q;
	vector<_T> factors;
	for(int i=0;i<13;i++){
		while(n%a[i]==0){
			factors.push_back(a[i]);
			n/=a[i];
		}
	}
	q.push(n);
	while(!q.empty()){
		_T x=q.front();_T r=x;
		q.pop();
		if(x==1) break;
		if(MillerRabin(x)){
			factors.push_back(x);
			continue;
		}
		for(int i=0;i<accuracy_factor and a[i]<x;i++){
			_T y=pho(x,a[i]);
			if(y==1 or y==x)
				continue;
			q.push(y);x/=y;
			q.push(x);
			break;
		}
		if(x==r){///x is likely to be a power of prime , most likely squire, use seive for better performance;
			for(_T i=43;i*i<=x;i++){
				while(x%i==0){
					factors.push_back(i);
					x/=i;
				}
			}
			if(x-1)factors.push_back(x);
		}
	}
	sort(factors.begin(), factors.end());
	return factors;
}
