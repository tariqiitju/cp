1. #include <bits/stdc++.h>
2. using namespace std;
3. /**************** Hungarian Algorithm ******************/
4. const int INF=1e9;
5. const int N=500;
6. int Hun[N+2][N+2];
7. int Hungarian(int n,int m)
8. {
9.   vector<int>u(n+1),v(m+1),p(m+1),way(m+1);
10.   for(int i=1;i<=n;i++)
11.   {
12.     p[0]=i;int j0=0;
13.     vector<int>minv(m+1,INF);
14.     vector<char>used(m+1,false);
15.     do
16.     {
17.       used[j0]=true;int i0=p[j0],delta=INF,j1;
18.       for(int j=1;j<=m;j++)
19.       {
20.         if(!used[j])
21.         {
22.           int cur=Hun[i0][j]-u[i0]-v[j];
23.           if(cur<minv[j])minv[j]=cur,way[j]=j0;
24.           if(minv[j]<delta)delta=minv[j],j1=j;
25.         }
26.       }
27.       for(int j=0;j<=m;j++)
28.       {
29.         if(used[j])u[p[j]]+=delta,v[j]-=delta;
30.         else minv[j]-=delta;
31.       }
32.       j0=j1;
33.     }while(p[j0]!=0);
34.     do 
35.     {
36.       int j1=way[j0];p[j0]=p[j1];
37.       j0=j1;
38.     }while(j0);
39.   }
40.   int ret=0;
41.   for(int i=1;i<=m;i++)ret+=Hun[p[i]][i];
42.   return ret;
43. }
