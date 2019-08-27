Adding character at end: h*base+c
Deleting character from beginning: h-base^(length of current string -1)
Adding character at beginning: c*base^(length of current string )+h
Deleting character from end : imposible :D
Concatenation: h1, h2 is hash of S1 and S2 now hash(S1 + S2)=h1*base^(S2.length) + h2
Let's say h(i)= hash(S0..Si)
Then hash(Si..Sj)=(h(j)-h(i-1) )/p^i
Polynomial Hash : h[i] = h[i-1]  + base^(a[i]) [anagram check]
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")//com error
#pragma GCC optimize("unroll-loops")
