const int LMT               =5e6+5;//http://mathworld.wolfram.com/HarmonicNumber.html
double H[LMT+5];
const double gamm = 0.5772156649;
//0.57721566490153286060651209008240243104215933593992 as much as you need
double Bn[] = {1.0/6.0, -1.0/30.0, 1.0/42.0, -1.0/30.0, 5.0/66.0};
H[1]=1;for(int i=2;i<=LMT;i++)H[i]=H[i-1]+1.0/i;
double Har(int n){
    if(n<LMT)  return H[n];
    double r = log(n) + gamm + .5/n;
    for(int i = 0; i < 5; i++) {
        r -= (Bn[i] / (2.0*(i+1)*pow(n,2*(i+1)))) ;
    }
    return r;
}
