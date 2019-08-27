.i] which is equal to it’s prefix
#include <bits/stdc++.h>
using namespace std;
const int MX=2e6+500;
int __a[MX];
int* genf(char *p,int m){
    int *f=__a;
    int i=1,j=0;
    f[0]=0;
    while(i<m){
        while(j>0 && p[j]!=p[i])j=f[j-1];
        if(p[j]==p[i])j++;
        f[i]=j;
        i++;
    }
    return f;
}
void kmp(char *t,char *p,int n,int m,int *f){
    int i=0,j=0;
    while(i<=n-m){
        while(j>0 && p[j]!=t[i])j=f[j-1];
        if(p[j]==t[i]){
            j++;
            if(j==m){
                j=f[j-1];
                //match start at index i-m+1
            }
        }
        i++;
    }
}
