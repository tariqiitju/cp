ncr[0][0]=1;
for(int i=1;i<=N;i++){
    ncr[i][0]=1;
    for(int j=1;j<=i;j++){
        ncr[i][j]=(ncr[i-1][j] + ncr[i-1][j-1])%moduli;
    }
}
