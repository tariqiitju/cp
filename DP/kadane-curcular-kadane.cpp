//1D maximum sub array
ll kadane(int a[], int n)
{
//only works if array has at least one non negative element
    ll max_so_far = LLONG_MIN, max_ending_here = 0;
    int i;
    for (i = 0; i < n; i++){
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
///1D maximum subarray circular
ll maxCircularSum(int a[], int n)
{
   ll max_kadane = kadane(a, n);
   ll max_wrap = 0, i;
   for (i=0; i<n; i++){
        max_wrap += a[i]; 
        a[i] = -a[i];
   }
   max_wrap = max_wrap + kadane(a, n);
   return max(max_wrap , max_kadane);
}
