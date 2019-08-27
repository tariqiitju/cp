int marked[100005],prime_count[100005],notSqFree[100005],mobius[100005];
void mobius_precal(int n){
    for(int i=2;i<=n;i++){
        if(not marked[i]){
            for(int j=i;j<=n;j+=i){
                prime_count[j]++;
                marked[j]=(j!=i);
            }
            for(ll j=(i*1LL)*i;j<=n;j+=i*i)
                notSqFree[j]=1;
        }
    }
    mobius[1]=1;
    for(int i=2;i<=n;i++)
        mobius[i]=(!notSqFree[i])*(prime_count[i]&1 ? -1 :1);
}
ll totalsqfree(ll n){
    ll ans=0;
    for(ll i=1;i*i<=n;i++)
        ans+=mobius[i]*(n/(i*i));
    return ans;
}
