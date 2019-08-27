ll max_xor_sum(ll *a,int n){
	ll ans=0;
	for(int c=63;c--;)
	{
		sort(a,a+n,greater<ll>());
		ans=max(ans,ans^a[0]);
		int p=__builtin_clzll(a[0]);
		ll q=a[0];
		if(!q)break;
		int i=0;
		while(i<n && __builtin_clzll(a[i])==p )a[i]^=q,i++;
 
	}
	return ans;
}
