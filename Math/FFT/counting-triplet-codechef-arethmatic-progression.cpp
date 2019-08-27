/*
Arithmetic progression (codechef) : count the number of (i,j,k) triplet , such i<j<k and  A[j] - A[i] = A[k] - A[j]. size of A is n <= 105 and 0 < A[i] < 30001. 
From the given relation , 2*A[j] = A[i] + A[k] and A[k] = 2*A[j] - A[i] and A[i] = 2*A[j] - A[k] . 
We choose a len L such L = N/sqroot(fft_complexity), then we divide array into d segment of length L (may be except the last one). We maintain 3 buckets of number , pre,post,ins. Pre contain frequency of all the number prior to current segment, post contain all the number next to current segment. We calculate all the triplet of several type
    1.(i,j,k) all in current segment
    2.(j,k) in current segment i in pre bucket
    3.(i,j) in current segment k in post bucket
Only j in current bucket , i in pre and j in post bucket.
For First 3 types we run L^2 bruteforce loop.  For the last type , we multiply pre,post by fft. And collect the result.
*/
for(int seg_i=0;seg_i < nseg;seg_i++){//all the numbers in post bucket, pre and ins are empty
    int start = seg_i * Len;
    int End = min(n, (seg_i + 1)*Len );
    for(int i=start;i<End;i++)post[a[i]]--;
    for(int j=start;j<End;j++){
        for(int k=j+1;k<End;k++){
            int p = 2*a[j] - a[k];
            Ans += (p>=0 && p<=30000 ? pre[p] + ins[p] : 0);[searching i]
            p = 2*a[k] - a[j];[assuming k is j , j is i , searching for k]
            Ans += (p>=0 && p<=30000 ? post[p] : 0);
        }
        ins[a[j]]++;
    }
    A.resize(30001);
    B.resize(30001);
    for(int i=0;i<=30000;i++)
        A[i] = pre[i],B[i]=post[i];
    Mul(A,B);//FFT multiplication
    for(int i=start;i<End;i++)
        pre[a[i]]++,ins[a[i]]--,Ans+=res[a[i]<<1];
}
