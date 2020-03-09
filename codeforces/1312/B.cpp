#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        sort(a, a + n); reverse(a, a + n);
        for(int i : a) {
            printf("%d ", i);
        }
        printf("\n");
    }
}