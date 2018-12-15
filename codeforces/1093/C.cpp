#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long b[200010];
long long a[200010];
const long long inf = 2e18;

int main() {
    //ios_base :: sync_with_stdio (false);
    //cin.tie(0);

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= (n / 2); i++) {
        scanf("%lld", &b[i]);
    }
    long long last = inf;
    for(int i = 1; i <= (n / 2); i++) {
        long long mn = b[i] - min(last, b[i]);
        mn = max(mn, a[i - 1]);
        a[i] = mn;
        a[n - i + 1] = b[i] - mn;
        last = a[n - i + 1];
    }
    for(int i = 1; i <= n; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
    return 0;
}
