//Non-prime constant moduli:
ll k[20][MX];
ll f[MX];
const ll moduli = 521254688;
int phi;
vector<int> prime;
void pre(int N){//N is largest input
    int n=moduli;
    phi=moduli;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0)
                n/=i;
            prime.pb(i);
            phi-=phi/i;
        }
    }
    if(n>1){
        phi-=phi/n;
        prime.pb(n);
    }
    f[0]=1;
    for(int j=1;j<=N;j++){
        int n=j;
        for(int i=0;i<SZ(prime);i++){
            k[i][j]=k[i][j-1];
            while(n%prime[i]==0){
                k[i][j]++;
                n/=prime[i];
            }
        }
        f[j]=(f[j-1]*n)%moduli;
    }
}
int ncr(int n,int r){
    ll ans = f[n]*pow( (f[r]*f[n-r])%moduli,phi-1,moduli) %moduli;
    for(int i=0;i<SZ(prime);i++){
        ans*=pow(prime[i],k[i][n]-k[i][r]-k[i][n-r],moduli);
        ans%=moduli;
    }
    return ans;
}
