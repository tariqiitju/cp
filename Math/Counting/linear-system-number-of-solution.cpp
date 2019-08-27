int count_solutions_of_a_linear_system(int *a,int * b,int q,int n){
	//x_0 + x_1 + .. + x_q = n
    //a[i] <= x_i <= b[i] 
    for(int i=0;i<q;i++){
		n -= a[i];		//getting rid of lower bound
		a[i] = b[i] - a[i];
	}
	int ans = 0;int s[]={1,-1};//s[0] = sign of even entry
	for(int ms = 0; ms < (1<<q) ;ms++){
		int N = n,c=0;
		for(int i = 0; i < q; i++){
			if((ms>>i)&1)c^=1,N-=a[i]+1;//converting conditions
		}
		if(N>=0)
		{
			ans+=s[c]*ncr(N+q-1,q-1);
			if(ans<0)ans+=mod;
			if(ans>=mod)ans-=mod;
		}//else 0 will be contributed
	}
	return ans;
}
