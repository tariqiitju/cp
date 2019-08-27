Depends on: distsub(int node) to precal d[]
long long dp[_Z<<1];
long long lensub(int u){
    if(dp[u])return dp[u];
    for(int i=0;i<_Y;i++)
        if(Ax[u].e[i])
            dp[u]+=d[Ax[u].e[i]]+lensub(Ax[u].e[i]);
        return dp[u];
}
lensub(root) is the answer.