#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn];
long long sum[maxn], suf[maxn];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  k += 1;
  sort(a, a + n);
  for(int i = n - 1; i >= 0; i--) {
    sum[i] = sum[i + 1] + 1LL * a[i] * i;
    suf[i] = suf[i + 1] + a[i];
  }
  auto func = [&] (int i, int j) {
    return sum[i] + suf[i] * (j - i); 
  };
  long long total = 0;
  long long ans = func(0, 0);
  for(int i = 0; i < n; i++) {
    total += 1LL * (i / k) * a[i];
    ans = max(ans, total + func(i + 1, (i / k) + 1));
  }
  printf("%lld\n", ans);
  return 0;
}
