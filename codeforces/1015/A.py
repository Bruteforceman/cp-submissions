n, m = map(int, input().split())
a = [0] * (m + 1)
for i in range(n):
    l, r = map(int, input().split())
    for j in range(l, r + 1):
        a[j] = 1
cnt = 0
for i in range(1, m + 1):
    if a[i] is 0:
        cnt = cnt + 1
print(cnt)
arr = []
for i in range(1, m + 1):
    if a[i] is 0:
        arr.append(str(i))

print(' '.join(arr))
