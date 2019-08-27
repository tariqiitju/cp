long long d[_Z<<1];
long long distsub(int u){
    if(d[u]) return d[u];
    d[u]=1;
    for(int i=0;i<_Y;i++)
        if(Ax[u].e[i])d[u]+=distsub(Ax[u].e[i]);
    return d[u];
}
