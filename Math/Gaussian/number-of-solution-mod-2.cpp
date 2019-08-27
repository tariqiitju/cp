const int N=901;
int po[1000];///po[i]=2^i % mod
int gauss (vector < bitset<N> > a, int n, int m) {
	/*
	n is number of equations
	and m is number of variable
	*/
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }
        // The rest of implementation is the same as above
    vector<int> ans(m,0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1){

            ans[i] = a[where[i]][m]; ;
            if(!a[where[i]][i]) return 0;
        }
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum ^= (ans[j] & a[i][j]);
        if (sum != a[i][m])
            return 0;
    }
    int k=0;
    for (int i=0; i<m; ++i)
        k+=(where[i] == -1);
            
    return po[k];
}
