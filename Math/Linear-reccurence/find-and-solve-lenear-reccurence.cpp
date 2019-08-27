const int MX = 233333;
inline ll pow(ll a,ll b,ll m){
	ll ans=1%m;a%=m;
	for(;b;b>>=1){
		if(b&1)ans=(ans*a)%m;
		a=(a*a)%m;
	}
	return ans;
}
namespace linear_seq {
	int MOD = mod;
	inline vector<ll> BM(vector<ll> x){
		//ls: (shortest) relation sequence (after filling zeroes) so far
		//cur: current relation sequence
		vector<ll> ls,cur;
		//lf: the position of ls (t')
		//ld: delta of ls (v')
		int lf,ld;
		for(int i=0;i<int(x.size());++i)
		{
			ll t=0;
			//evaluate at position i
			for(int j=0;j<int(cur.size());++j)
				t=(t+x[i-j-1]*(ll)cur[j])%MOD;
			if((t-x[i])%MOD==0) continue; //good so far
			//first non-zero position
			if(!cur.size())
			{
				cur.resize(i+1);
				lf=i; ld=(t-x[i])%MOD;
				continue;
			}
			//cur=cur-c/ld*(x[i]-t)
			ll k=-(x[i]-t)*pow(ld,MOD-2,MOD)%MOD/*1/ld*/;
			vector<ll> c(i-lf-1); //add zeroes in front
			c.push_back(k);
			for(int j=0;j<int(ls.size());++j)
				c.push_back(-ls[j]*k%MOD);
			if(c.size()<cur.size()) c.resize(cur.size());
			for(int j=0;j<int(cur.size());++j)
				c[j]=(c[j]+cur[j])%MOD;
			//if cur is better than ls, change ls to cur
			if(i-lf+(int)ls.size()>=(int)cur.size())
				ls=cur,lf=i,ld=(t-x[i])%MOD;
			cur=c;
		}
		for(int i=0;i<int(cur.size());++i)
			cur[i]=(cur[i]%MOD+MOD)%MOD;
		return cur;
	}
	int m; //length of recurrence
	//a: first terms
	//h: relation
	ll a[MX],h[MX],t_[MX],s[MX],t[MX];
	//calculate p*q mod f
	inline void mull(ll*p,ll*q)
	{
		for(int i=0;i<m+m;++i) t_[i]=0;
		for(int i=0;i<m;++i) if(p[i])
			for(int j=0;j<m;++j)
				t_[i+j]=(t_[i+j]+p[i]*q[j])%MOD;
		for(int i=m+m-1;i>=m;--i) if(t_[i])
			//miuns t_[i]x^{i-m}(x^m-\sum_{j=0}^{m-1} x^{m-j-1}h_j)
			for(int j=m-1;~j;--j)
				t_[i-j-1]=(t_[i-j-1]+t_[i]*h[j])%MOD;
		for(int i=0;i<m;++i) p[i]=t_[i];
	}
	inline ll calc(ll K)
	{
		for(int i=m;~i;--i)
			s[i]=t[i]=0;
		//init
		s[0]=1; if(m!=1) t[1]=1; else t[0]=h[0];
		//binary-exponentiation
		while(K)
		{
			if(K&1) mull(s,t);
			mull(t,t); K>>=1;
		}
		ll su=0;
		for(int i=0;i<m;++i) su=(su+s[i]*a[i])%MOD;
		return (su%MOD+MOD)%MOD;
	}
	inline int work(vector<ll> x,ll n)
	{
		if(n<int(x.size())) return x[n];
		vector<ll> v=BM(x); m=v.size(); if(!m) return 0;
		for(int i=0;i<m;++i) h[i]=v[i],a[i]=x[i];
		return calc(n);
	}
}
using linear_seq::work;	//call work(sequence_in_a_vector,n) : will return n'th term in the sequence
					   	//works well when a uniquly defines the sequence
						//ie , if reccurrence size if p , there must be p term which created by the recurrence
						//tested
						//complexity (given_sequence_size ^ 2) + log(n) 

