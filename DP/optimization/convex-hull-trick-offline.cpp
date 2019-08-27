#include <bits/stdc++.h>
using namespace std;
#define xx 		first
#define yy 		second
typedef long long ll;
typedef pair<ll,ll> pll;
///min query increasing slope 
///or max query decreasing slope 
double intersect(pll a,pll b){
    return (b.yy-a.yy+0.0)/(a.xx-b.xx);
}
void insert(pll candi,pll *stk,double *inter,int &top){
	while(top>0 && intersect(stk[top-1],stk[top])>=intersect(stk[top-1],candi))top--;
    stk[++top]=candi;
    inter[top]=intersect(stk[top-1],candi);
}
ll qry(ll x,pll *stk,double *inter,int top){
	int j=upper_bound(inter+1,inter+top+1,x)-inter-1;
    return stk[j].xx*(x)+stk[j].yy;
}
void ini(pll candi,double base,pll *stk,double *inter,int &top){
	top=0;
	stk[0]=candi;
	inter[0]=base;
}
