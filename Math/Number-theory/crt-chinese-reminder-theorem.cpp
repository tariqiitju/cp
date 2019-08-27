/** Works for non-coprime moduli.
 Returns {-1,-1} if solution does not exist or input is invalid.
 Otherwise, returns {x,L}, where x is the solution unique to mod L
*/
int chinese_remainder_theorem( vector<int> A, vector<int> M ) {
    /**
    return x,L such that
    x%M[i]=A[i] and L is such number where x is unique
    */
    typedef __int128 INT;
    if(A.size() != M.size()) return -1; /** Invalid input*/
    int n = A.size();
    INT a1 = A[0];
    INT m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/
    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) {
        INT a2 = A[i];
        INT m2 = M[i];
        INT g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return -1; /** No solution exists*/
        /** Merge the two equations*/
        INT p, q;
        egcd(m1/g, m2/g, p, q);
        INT mod = (m1 / g) * m2; /** LCM of m1 and m2*/
        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        INT x = (a1*   (((m2/g)*q)%mod) + a2* (((m1/g)*p) %mod ) ) % mod;
        /** Merged equation*/
        a1 = x;
        if (a1 < 0) a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    return a1==0 ? m1 : a1;//be sure what do you want to return actually,result is a1 , result is unique in modulo m1 ,(a1 + x*m1) is also valid result for any integer x
}
inline int crt(vector<int>&ao,vector<int> &mo){//gcd(mo[i],mo[j]) = 1, for any (i,j) such i!=j 
	int sz = (int) ao.size();
	int n = 1;for(int p : mo)n*=p; int res = 0;
	for(int i = 0;i<sz;i++)
	{
		ll m_i = n/mo[i];
		ll m_inv,ing;
		egcd(m_i,mo[i]*1LL,m_inv,ing);
		if(m_inv < 0)m_inv+=mo[i];
		res = (res + ((m_i * m_inv) % n) * ao[i])%n ; //be very careful with overflow
	}
	return res;
}

