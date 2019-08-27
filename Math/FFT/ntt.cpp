/*
if bruteforce needed at some point,
consider eliminating zero frequency term
*/
template<class T>inline T pow(T a,T b,T m){
	a%=m;T ans=1%m;
	while(b){
		if(b&1)ans*=a,ans%=m;
		a*=a;a%=m;b>>=1;
	}
	return ans;
}
typedef long long ll;
ll MOD,ROOT;
void ntt ( vector < ll > & a, bool inv ) {
    int n = ( int ) a. size ( ) ;
    for(int i = 1 , j = 0 ; i < n ; ++ i ) {
        int bit = n >> 1 ;
        for ( ; j >= bit ; bit >>= 1 ) j -= bit ;
        j += bit ;
        if ( i < j ) swap ( a [ i ] , a [ j ] ) ;
    }
    for ( int len = 2 ; len <= n ; len <<= 1 ) {
        ll wlen=pow(ROOT,(MOD-1)/len,MOD);///can be precalculated
        if(inv)wlen=pow(wlen,MOD-2,MOD);///can be precalculated
        for ( int i = 0 ; i < n ; i += len ) {
            ll w=1;
            for ( int j = 0 ; j < len / 2 ; ++ j ) {
                ll u = a [ i + j ] ; 
                ll v = a [ i + j + len / 2 ] * w ;
                v%=MOD;
                a [ i + j ] = (u + v)%MOD; ;
                a [ i + j + len / 2 ] = (u - v)%MOD ;
                w *= wlen ;
                w%=MOD;
            }
        }
    }
    if ( inv )
    {
        ll MOD_INV_OF_N=pow(n*1ll,MOD-2,MOD);///can be precalculated
        for ( int i = 0 ; i < n ; ++ i )
            a[i]*=MOD_INV_OF_N,
            a[i]%=MOD;
    }
}
vector<ll>res;
void Mul( const vector < ll > & a, const vector < ll > & b) {
    vector < ll > fa ( a. begin ( ) , a. end ( ) ) ,  fb ( b. begin ( ) , b. end ( ) ) ;
    ///Do bruteforce here if needed
    size_t n = 1 ;
    while ( n < max ( a. size ( ) , b. size ( ) ) )  n <<= 1 ;
    n <<= 1 ;
    fa. resize ( n ) ,  fb. resize ( n ) ;
    ntt ( fa, false ) ,  ntt ( fb, false ) ;
    for ( size_t i = 0 ; i < n ; ++ i )
        fa [ i ] *= fb [ i ] ,fa[i]%=MOD;
    ntt ( fa, true ) ;
    res.resize(n);
    for( size_t i = 0 ; i < n ; ++ i ) {
        res[i] = (ll) (fa[i]);
        if(res[i]<0)res[i]+=MOD;
    }
    ///res[i] = number of pair(x,y) such a[x] + b[y] ==i
}
