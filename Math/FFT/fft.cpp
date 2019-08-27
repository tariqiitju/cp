/*
if bruteforce needed at some point,
consider eliminating zero frequency term
*/
//typedef complex < double > cpx ;
struct cpx{
	double r,i;
	cpx(){r=i=0;}
	cpx(double real){r=real,i=0;}
	cpx(double real,double imag){r=real,i=imag;}
	inline double real(){return r;}
	cpx operator + (cpx w){return cpx(r+w.r,i + w.i);}
	cpx operator - (cpx w){return cpx(r-w.r,i - w.i);}
	cpx operator /= (double x){r/=x,i/=x;return *this;}
	cpx operator * (cpx w){return cpx(r*w.r-i*w.i,r*w.i+i*w.r);}
	cpx operator *= (cpx w){return *this=cpx(r*w.r-i*w.i,r*w.i+i*w.r);}
};
typedef long long ll;
const double PI = acos(-1);
void fft ( vector < cpx > & a, bool inv ) {
    int n = ( int ) a. size ( ) ;
    for(int i = 1 , j = 0 ; i < n ; ++ i ) {
        int bit = n >> 1 ;
        for ( ; j >= bit ; bit >>= 1 ) j -= bit ;
        j += bit ;
        if ( i < j ) swap ( a [ i ] , a [ j ] ) ;
    }
    for ( int len = 2 ; len <= n ; len <<= 1 ) {
        double ang = 2 * PI / len * ( inv ? - 1 : 1 ) ;
        cpx wlen ( cos ( ang ) , sin ( ang ) ) ;
        for ( int i = 0 ; i < n ; i += len ) {
            cpx w ( 1 ) ;
            for ( int j = 0 ; j < len / 2 ; ++ j ) {
                cpx u = a [ i + j ] ,  v = a [ i + j + len / 2 ] * w ;
                a [ i + j ] = u + v ;
                a [ i + j + len / 2 ] = u - v ;
                w *= wlen ;
            }
        }
    }
    if ( inv )
        for ( int i = 0 ; i < n ; ++ i )
            a [ i ] /= n ;
}

vector<ll>  Mul( const vector < double > & a, const vector < double > & b) {
    vector < cpx > fa ( a. begin ( ) , a. end ( ) ) ,  fb ( b. begin ( ) , b. end ( ) ) ;
    size_t n = 1 ;
    while ( n < max ( a. size ( ) , b. size ( ) ) )  n <<= 1 ;
    n <<= 1 ;
    fa. resize ( n ) ,  fb. resize ( n ) ;
    fft ( fa, false ) ,  fft ( fb, false ) ;
    for ( size_t i = 0 ; i < n ; ++ i )
        fa [ i ] *= fb [ i ] ;
    fft ( fa, true ) ;
    vector<ll>res;res.resize(n);
    for( size_t i = 0 ; i < n ; ++ i ) {
        res[i] = (ll) (round(fa[i].real()));
    }return res;
}
