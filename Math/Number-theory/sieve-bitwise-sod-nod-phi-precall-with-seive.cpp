Optimal sieve
const int MX=1e6;
bool p[MX];
p[0]=p[1]=1;
for(int i=4;i<=MX;i+=2)
    p[i]=1;
for(int i=3;i*i<=MX;i+=2){
    if(!p[i])
        for(int j=i*i;j<=MX;j+=i+i)
            p[j]=1;
}
Bitwise : 
int p[(MX>>5)+5];
#define check(i)    ((p[(i)>>5]>>((i)&31))&1)
#define mark(i)     (p[(i)>>5]|=(1<<((i)&31)))
Nod : ans=1, for each prime factor : ans*=(frequenci+1)
Sod : ans=1, for each prime factor : ans*=(prime^(frequency+1) -1)/(prime-1)
Phi : ans=n, for each prime factor : ans-=ans/prime
Using sieve for precalculating sod,nod,phi
for(int i=0;i<=MX;i++)
    nod1[i]=1;
for(int i=2;i<=MX;i++){
    if(not check(i)){
        for(int j=i;j<=MX;j+=i){
            int c=0,n=j;
            while(n%i==0)c++,n/=i,p2++;
            mark(j);
            nod[j]*=c+1;//sod and phi in similar way
        }
    }
}
for(int i=0;i<=MX;i++)
    phi[i]=i;
for(int i=2;i<=MX;i++){
if(not v[i]){
	    for(int j=i;j<=MX;j+=i){
	            v[j]=1;
	            phi[j]-=phi[j]/i;
	     }
	 }
}
