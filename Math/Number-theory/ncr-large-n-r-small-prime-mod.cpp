//Large n,r small prime modulo 
inline ll factorial(int k,int p){
	ll ans=1;for(int i=2;i<=k;i++)ans=(ans*i)%p;///if p is constant , precal this function
	return ans;
}
pair<ll,ll> sep(ll n,int p){
	/**	let n!=a*(p^k) such a%p!=0
		then this function return {a%p,k}
		p is prime
	*/
	ll k=n/p;
	if(k<p){
		ll ans = (k&1) ? ((p-1)*factorial(n%p,p) % p)*factorial(k,p) %p : factorial(n%p,p)*factorial(k,p)%p;
		return {ans, k};
	}else{
		pair<ll, ll> w = sep(k,p);
		ll ans = (k&1) ? ((p-1)*factorial(n%p,p) % p)*w.xx %p : factorial(n%p,p)*w.xx %p;
		return {ans, k + w.yy};
	}
}
ll ncr(ll n,ll r,int p){//p is prime [small/iterable ]
	pair<ll,ll> a = sep(n,p);
	pair<ll,ll> b = sep(r,p);
	pair<ll,ll> c = sep(n-r,p);
	if(a.yy-b.yy-c.yy) return 0;
	return a.xx*pow(b.xx*c.xx%p,p-2,p) % p;
}
