def millerrabin(n):
    a=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 , 97]
    if n==2 or n==3:
        return True
    if n<2 or n%2==0:
        return False
    r=0
    s=n-1
    while s%2==0:
        s>>=1
        r+=1
    for i in a:
        if i>=n: return True
        x=pow(i,s,n)
        if x==1 or x==n-1:
            continue
        composite=True
        for k in range(r):
            x*=x
            x%=n
            if x==n-1:
                composite=False
                break
            if x==1:
                return False
        if composite:
            return False
    return True
