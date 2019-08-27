vector<double> dvand_real ( vector<double> alpha,vector<double>b){
  int n = (int)alpha.size();
  int j;
  int k;
  vector<double> x(b.begin(),b.end());
  for ( k = 0; k < n - 1; k++ ){
    for ( j = n - 1; k < j; j-- ){
      x[j] = ( x[j] - x[j-1] ) / ( alpha[j] - alpha[j-k-1] );
    }
  }

  for ( k = n - 2; 0 <= k; k-- ){
    for ( j = k; j < n - 1; j++ ){
      x[j] = x[j] - alpha[k] * x[j+1];
    }
  }
  return x;
}
