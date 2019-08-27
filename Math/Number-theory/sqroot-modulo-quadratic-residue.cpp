namespace sqroot_modulo{
    int P,w;
    struct cp{
        long long x,y;
        inline cp operator*(cp const&_)const{
            return (cp){(x*_.x+y*_.y%P*w)%P,(x*_.y+y*_.x)%P};
        }
    };
    cp pow_1(cp x,int k){
        cp res=(cp){1,0};
        for(;k!=0;k>>=1){
            if(k&1) res=res*x;
            x=x*x;
        }
        return res;
    }
    long long Quadratic_residue(long long x,int P){
        Cioplla::P=P;
        x=(x%P+P)%P;
        if(x==0) return 0;
        if(::pow(x,(P-1)>>1,P)!=1) return -1;
        long long tmp;
        do tmp=((long long)rand()<<31|rand())%P;
        while(::pow((tmp*tmp+P-x)%P,(P-1)>>1,P)!=P-1);
        w=(tmp*tmp-x)%P;
        return (pow_1((cp){tmp,1},(P+1)>>1).x+P)%P;
    }
}
