#include<iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;
#define 	xx		first
#define		yy		second
typedef		int		T 	  ;		///Treap Datatype
const		int		MX=3e5;
int  		_cnt	=2;	
typedef		pair<int,int> pii; 
T data[MX];
int lft[MX],rght[MX],prio[MX],sz[MX];
/**
	0 is null and these gonna always hold
	data[0]=lft[0]=rght[0]=prio[0]=sz[0]=0;
	we will use these identity implicitely
*/
inline int New(T value)
{
	data[_cnt]=value;
	lft[_cnt]=rght[_cnt]=0;
	sz[_cnt]=1;prio[_cnt]=rand();
	return _cnt++;
}
inline void upd(int node)
{
	if(node)sz[node]=sz[ lft[node] ]+sz[ rght[node] ] + 1;
	//sum[node]=sum[ lft[node] ]+sum[ rght[node] ] + data[node];
}
///Split By Value : return two treap , first one contains
/// all values less-equal Val, second one contain remaining
void splitv(int node,int &l,int &r,T val)
{
	if(!node) {l=r=0;return;}
	if( data[node] <= val)
	{
		splitv(rght[node],rght[node] , r, val);
		l=node;
	}else 
	{
		splitv(lft[node],l, lft[node],val);
		r=node;
	}
	upd(node);
}
///Split By Size : return two treap 
///first one is of size s (smallest) [if sz[node]<s then size of first one is sz[node], and second one is 0]
///second one contains remaining
void splits(int node,int &l,int &r,int s)
{
	if(!node){l=r=0;return;}
	if(!s) {r=node;l=0;}
	else if(sz[node]<=s) {l=node;r=0;}
	else if(sz[ lft[node] ] >= s)
	{
		r=node;
		splits(lft[node],l, lft[node], s);
	}else 
	{
		l=node;
		splits(rght[node], rght[node] ,r, s -1-sz[ lft[node] ] );
	}
	upd(l);upd(r);
}
//Join : Join two treap l,r max in l must be <= min in r
int join(int l,int r)
{
	if (!l || !r)   return l?l:r;
	if(prio[l] > prio[r])
	{
		rght[l]=join( rght[l],r );
		upd(l);
		return l;
	}else 
	{
		lft[r]=join(l,lft[r]);
		upd(r);
		return r;
	}
}
//Split By Sum
///sum of first one is <= s
#define sum(x)	0
void splitsum(int node,int &l,int &r,int s)
{
    if(!node){l=r=0;return;}
    if(sum(node) <= s ){l=node;r=0;}
    else if(!s){r=node;l=0;}
    else if(sum(lft[node]) >= s ) 
    {
    	r=node;
		splitsum(lft[node],l, lft[node], s);
    }

    else if(s < sum(lft[node]) + data[node]  ) 
    {
        ///current node with right child goes to right , rest goes to left
        r=node;
        l=lft[node];
        lft[node]=0;
        
    }
    else
    {
    	l=node;
		splitsum(rght[node], rght[node] ,r, s -data[node]-sum( lft[node] ) );
    }
    upd(l);upd(r);
}
///Merge
///similar with join but no restriction
int merge(int a, int b)
{
    if (!a || !b)   return a?a:b;
    if(prio[b] > prio[a])swap(a,b);
    int l,r;
    splitv(b,l,r,data[a]);
    lft[a]=merge(lft[a],l);
    rght[a]=merge(rght[a],r);
    return a;
}
