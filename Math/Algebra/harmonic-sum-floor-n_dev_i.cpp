ll p = n + 1,res = 0;
for(ll i = 1;i*i<=n;i++){
	res+=n/i;
	if(i*i!=n)
	{
		res+= i*((n/i) - max(n/(i+1),i));
	}
}
