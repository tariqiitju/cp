Calculate modular inverse of all number till n (mod m) in O(n) time (work for prime only)
r[1] = 1;
for(int i = 2; i <= n ; ++i)
    r[i] = (m - (m/i) * r[m%i] % m) % m;
If m if prime : pow(a,m-2,m) else pow(a,phi(m)-1,m)
Prime only:
template <class T> T inv(T a,T m){
    if(a==1) return a;
    return (((m-m/a)*inv(m%a,m))%m + m)%m;
}
