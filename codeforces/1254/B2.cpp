#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18;
const int maxn = 1e6 + 10;
int a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  long long sum = accumulate(a, a + n, 0LL);
  vector <long long> factors;
  for(int i = 2; 1LL * i * i <= sum; i++) {
    if(sum % i == 0) {
      factors.push_back(i);
      while(sum % i == 0) sum /= i;
    }
  }
  if(sum > 1) factors.push_back(sum);
  long long ans = inf;
  for(auto i : factors) {
    long long total = 0, moves = 0;
    for(int j = 0; j < n; j++) {
      total += a[j];
      moves += min(total % i, i - (total % i));
    }
    ans = min(ans, moves);
  }
  if(ans >= inf) ans = -1;
  printf("%lld\n", ans);
  return 0;
}
