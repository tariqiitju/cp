def xgcd(a, b):
    """return (g, x, y) such that a*x + b*y = g = gcd(a, b)"""
    x0, x1, y0, y1 = 0, 1, 1, 0
    while a != 0:
        q, b, a = b // a, a, b % a
        y0, y1 = y1, y0 - q * y1
        x0, x1 = x1, x0 - q * x1
    return b, x0, y0
def crt(A,M):
    sz = len(A)
    n = 1
    for p in M : n *= p
    res = 0
    for i in range(sz):
        m_i = n // M[i]
        g , m_i_inverse , ignore = xgcd(m_i,M[i])
        if m_i_inverse < 0 : m_i_inverse+=M[i]
        res = (res + m_i * m_i_inverse* A[i]) % n 
    return res
