const int LOGN =22;

int spt[LOGN][MX];
int par[MX];
void build(int n){

    for(int i=1;i<=n;i++)
        spt[0][i]=par[i];
    for(int j=1;(1<<j)<n;j++){
        for(int i=1;i<=n;i++){
            spt[j][i]= spt[j-1][i]?spt[i-1][ spt[i-1][j] ]:0;
        }
    }
}
int lev[MX];
int lca(int u,int v){
    if(lev[u] < lev[v])
        swap(u,v);
    for(int i = floor(log2(1 + lev[u] - lev[v])) ; lev[u] != lev[v] ;i--){
        if(lev[ spt[i][u] ] >= lev[v])
            u=spt[i][u];
    }
    if(u==v) return u;
    for(int i = floor(log2(1 + lev[u]));i>=0;i--){
        if(spt[i][u] != spt[i][v])
            u=spt[i][u] , v= spt[i][v];
    }
    return spt[0][u];
}
