vector<ll> dvand_mod ( vector<ll> alpha,vector<ll>b){
  int n = (int)alpha.size();
  int j;
  int k;
  vector<ll> x(b.begin(),b.end());
  for ( k = 0; k < n - 1; k++ ){
    for ( j = n - 1; k < j; j-- ){
      x[j] = (( x[j] - x[j-1] ) * inv[ (alpha[j] - alpha[j-k-1] + mod )%mod])%mod;//note the inv[x] = x^(-1) modulo mod
    }
  }
  for ( k = n - 2; 0 <= k; k-- ){
    for ( j = k; j < n - 1; j++ ){
      x[j] = (x[j] - alpha[k] * x[j+1])%mod;
    }
  }
  for(int i=0;i<n;i++)if(x[i]<0)x[i]+=mod;
  return x;
}
