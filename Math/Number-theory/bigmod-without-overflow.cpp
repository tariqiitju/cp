template<class T>inline T add(T a,T b,T m){//a,b<m
    return a>=m-b?a-(m-b):a+b;
}
ull multiply(ull a,ull b,ull m){
    ull ans=0;
    for(;b;b>>=1){
        if(b&1)ans=add(ans,a,m);
        a=add(a,a,m);
    }
    return ans;
}
ull pow(ull a,ull b,ull m){
    ull ans=1%m;
    for(;b;b>>=1){
        if(b&1)ans=multiply(ans,a,m);
        a=multiply(a,a,m);
    }
    return ans;
}
