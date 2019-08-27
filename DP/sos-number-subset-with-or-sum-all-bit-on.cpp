	for(int i = 0;i < (1<<N); ++i)
		F[i] = po[F[i]];
	ll res = 0;
	for(int i = 0;i < (1<<N); ++i){
		res = res + F[i] *(__builtin_popcount(i)&1 ? -1 : 1);
		res%=mod;
	}
	if(N&1) res =-res;
