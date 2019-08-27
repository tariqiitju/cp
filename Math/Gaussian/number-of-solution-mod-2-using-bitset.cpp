#define check(x,i)			(((x)>>(i))&1)
#define on(x,i)				((x)|=(1ULL<<(i)))			//very carefull with these ones (1LL,1ULL ,or 128 bit one)
#define off(x,i)			((x)&=(~(1ULL<<(i))))
#define toogle(x,i)			((x)^=(1ULL<<(i)))


//Number of solution of a system of linear equations modulo 2: using built in data types (int, long ,__int128) when number of variable is small
//typedef unsigned long long BitsSet;
**int po[1001];											///po[i]=2^i % mod
int gauss (vector < BitsSet > &a, int n, int m) {
	/*
	n is number of equations
	and m is number of variable
	*/
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (check(a[i], col)) {
                swap (a[i], a[row]);
                break;
            }
        if (! check(a[row], col))
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && check(a[i], col))
                a[i] ^= a[row];
        ++row;
    }
    // The rest of implementation is the same as above
    vector<int> ans(m,0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1){

            ans[i] = check(a[where[i]], m);
            if(!check(a[where[i]], i)) return 0;
        }
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum ^= (ans[j] & check(a[i], j));
        if (sum != check(a[i], m))
            return 0;
        
    }
    int k=0;
    for (int i=0; i<m; ++i)
        k+=(where[i] == -1);
            
    return po[k];
}
