Number of subset with xor sum 0 : create equation for each bit independently where each element is a boolean variable with coefficient value of corresponding bit[0 / 1] , all the variable sum up to 0 in modulo 2. Then number of solution to this system will be the answer.
Example a = {2,3,5,7,4} 
010,011,101,111,100
Equation for least significant bit  = x2 + x3 + x4 = 0 (modulo 2) [since a2 a3 and a4 has their corresponding bit on]
x1 + x1 + x4 = 0 (modulo 2) [for second lsb]
x3 + x4 + x5 = 0 (modulo 2) [for third lsb]


 Note : this is a very fast way with overall complexity m*m*n/64 [using bitset ]. n is number of bit [number of equation / number of row] and m is being size of array [number of variable / number of column]. We can achieve better complexity n*2n with fft if n is reasonably small (<=20). 
DO NOT BE CONFUSED , in gaussian we’ll have bit for each VARIABLE which is correspond to an elements existence in final solution.
Xi = 1 if we include a[i] in the set
Xi = 0 if we don't include a[i] in the set
