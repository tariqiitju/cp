/**
ensure
->last character is smallest among all (last one is 0)
->all chars are non negative integer (positive except last one)
*/
#include<bits/stdc++.h>
using namespace std;
int cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}
const int MX=2e6+500;
int __a[MX],__b[MX],__c[MX],__d[MX];
int* calsa(int *a,int n,int m)
{
    int *sa=__b,*b=__a,*x=__c,*y=__d,*t,i,j,p;
    memset(b, 0, m*sizeof(b[0]));
    for(i=0;i<n;i++) b[ x[i]=a[i]]++;
    for(i=1;i<m;i++)b[i]+=b[i-1];
    for(i=n-1;i>=0;i--) sa[ --b[ x[i] ] ]=i;

    for (j=1,p=1;p<n;j<<=1,m=p)
    {
        for(i=n-j,p=0;i<n;i++)y[p++]=i;
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;

        memset(b,0,m* sizeof(b[0]));
        for(i=0;i<n;i++)b[ x[ y[i] ] ]++;
        for(i=1;i<m;i++)b[i]+=b[i-1];
        for(i=n-1;i>=0;i--)sa[ --b[ x[ y[ i ] ] ] ]=y[i];

        for(t=x,x=y,y=t,x[ sa[0] ]=0,i=1,p=1;i<n;i++)
            x[ sa[i] ]= cmp(y,sa[i],sa[i-1],j)?p-1:p++;
    }
    return sa;
}
int * calh(int *sa,int *a,int n)
{
    ///ensure last character is smallest among all
    int *r=__a,*h=__c,j,i,k;
    for(int i=1;i<n;i++)r[ sa[i]]=i;
    n--;
    for(int i=0,k=0; i<n; h[ r[i++] ]=(k?k--:k))
        for(j=sa[ r[i]-1 ];a[i+k]==a[j+k];k++);
    h[0]=0;return h;
}
