int dp(int u){
    if(not u) return u;
    if(d[u]) return d[u];
    d[u]=_Z;
    for(int i=0;i<_Y;i++)
        d[u]=min(d[u],1 + dp(Ax[u].e[i]))
    return d[u];
}
