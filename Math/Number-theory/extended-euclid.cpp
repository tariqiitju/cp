template<class T> T egcd(T a, T b, T &x,T &y){///return ax+by=gcd(a,b)
    if(!b){
        x=1,y=0;return a;
    }
    T g=egcd(b,a%b,x,y);
    T xt=x;x=y,y=xt-(a/b)*y;
    return g;
}
