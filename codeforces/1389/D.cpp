#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long N, K;
  cin >> N >> K;
  long long L1, R1;
  long long L2, R2;
  cin >> L1 >> R1;
  cin >> L2 >> R2;
  long long res = LLONG_MAX;
  for(long long n = 1; n <= N; n++) {
    long long k = K;
    long long l1 = L1, r1 = R1, l2 = L2, r2 = R2;
    long long ans = 0;
    if(l1 > l2) {
      swap(l1, l2);
      swap(r1, r2);
    }
    if(r1 <= l2) {
      ans += (l2 - r1) * n;
      l2 = r1;
    } else {
      k -= (min(r1, r2) - l2) * n;
      k = max(0LL, k);
    }
    long long l = min(l1, l2);
    long long r = max(r1, r2);
    long long extra = ((l1 - l) + (l2 - l) + (r - r1) + (r - r2)) * n;
    if(k <= extra) {
      res = min(res, ans + k);
    } else {
      k -= extra;
      res = min(res, ans + extra + 2 * k);
    }
  }
  cout << res << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
