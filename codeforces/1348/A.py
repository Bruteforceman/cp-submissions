t = int(input())
for i in range(t):
    n = int(input())
    p, q = pow(2, n), 0
    for i in range(1, n):
        if i * 2 < n: p += pow(2, i)
        else: q += pow(2, i)
    print(abs(p - q))
