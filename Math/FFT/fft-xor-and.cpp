void fft_and(vector<ll> &P,bool inv){
	int n = (int)P.size();
	for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                ll u = P[i + j];
                ll v = P[i + len + j];
                if (!inv) {
                    P[i + j] = v;
                    P[i + len + j] = (u + v)%mod;
                } else {
                    P[i + j] = (-u + v)%mod;
                    P[i + len + j] = u;
                }
            }
        }
    }
}
vector<ll> multiply(vector<ll> a,vector<ll> b){
	size_t n = 1 ;
    while ( n < max ( a. size ( ) , b. size ( ) ) )  n <<= 1 ;
    n <<= 1 ;
    a. resize ( n ) ,  b. resize ( n ) ;
    fft_and ( a, false ) ,  fft_and ( b, false ) ;
    for ( size_t i = 0 ; i < n ; ++ i )
        a [ i ] *= b [ i ] ,a[i] %= mod;
    fft_and ( a, true ) ;
    for( size_t i = 0 ; i < n ; ++ i ) {
        if(a[i]<0)a[i]+=mod;
    }
    return a;
}
