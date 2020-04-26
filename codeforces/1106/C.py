def func(i, j) : return i < j
def rangeSort(arr, l, r, func):
    if r - l <= 1: 
        return 
    mid = (l + r) >> 1
    rangeSort(arr, l, mid, func)
    rangeSort(arr, mid, r, func)
    aux = [0] * (r - l)
    ptl, ptr = l, mid
    for i in range(len(aux)):
        if ptr == r or (ptl < mid and func(arr[ptl], arr[ptr])): 
            aux[i] = arr[ptl]
            ptl = ptl + 1
        else: 
            aux[i] = arr[ptr]
            ptr = ptr + 1
    for i in range(len(aux)):
        arr[l + i] = aux[i]

n = int(input())
a = [int(x) for x in input().split()]
# rangeSort(a, 0, len(a), func)
a.sort()
ans = 0
for i in range(n >> 1):
    ans = ans + (a[i] + a[n - i - 1]) * (a[i] + a[n - i - 1])
print(ans)


