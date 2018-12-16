#include <bits/stdc++.h>
using namespace std;
int a[200010];
int dp[200010];
int opt[200010];
long long x[200010];
const int inf = 1e9;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i += 2) {
        scanf("%d", &a[i]);
    }
    dp[0] = 0;
    for(int i = 2; i <= n; i += 2) {
        dp[i] = inf;
        for(int x = 1; x*x <= a[i]; x++) {
            if(a[i] % x == 0) {
                int p = x;
                int q = a[i] / x;
                if((q + p) & 1) continue;
                int aa = (q + p) / 2;
                int bb = (q - p) / 2;
                if(dp[i - 2] < bb) {
                    dp[i] = min(dp[i], aa);
                    if(dp[i] == aa) {
                        opt[i - 1] = bb;
                    }
                }
            }
        }
        if(dp[i] == inf) {
            puts("No");
            exit(0);
        }
    }
    for(int i = 1; i <= n; i += 2) {
        x[i] = 1LL * opt[i] * opt[i] - 1LL * dp[i - 1] * dp[i - 1];
    }
    for(int i = 2; i <= n; i += 2) {
        x[i] = a[i];
    }
    puts("Yes");
    for(int i = 1; i <= n; i++) {
        printf("%lld ", x[i]);
    }
    printf("\n");
}
