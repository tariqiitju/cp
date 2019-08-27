void fwht(vector<ll> &P,bool inv){
	int n = (int)P.size();
	for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                ll u = P[i + j];
                ll v = P[i + len + j];
                P[i + j] = (u + v)%mod;
                P[i + len + j] = (u - v)%mod;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++){
            P[i]=(P[i]*I[n % mod])%mod;//P[i]/=n
        }
    }
}
vector<ll> multiply(vector<ll> a,vector<ll> b){
	size_t n = 1 ;
    while ( n < max ( a. size ( ) , b. size ( ) ) )  n <<= 1 ;
    n <<= 1 ;
    a. resize ( n ) ,  b. resize ( n ) ;
    fwht ( a, false ) ,  fwht ( b, false ) ;
    for ( size_t i = 0 ; i < n ; ++ i )
        a [ i ] *= b [ i ] ,a[i] %= mod;
    fwht ( a, true ) ;
    for( size_t i = 0 ; i < n ; ++ i ) {
        if(a[i]<0)a[i]+=mod;
    }
    return a; res[x] = number of pair (i,j) such a[i]^a[j] == x
}
