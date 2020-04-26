def min(i, j): 
    if i > j: return j
    else: return i

def abs(i): 
    if i < 0: return -i
    else: return i

t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    a, b = map(int, input().split())
    print(abs(n - m) * a + min(n, m) * min(2 * a, b))

