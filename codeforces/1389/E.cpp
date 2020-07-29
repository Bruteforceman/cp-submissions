#include <bits/stdc++.h>
using namespace std;

void solve() {
  int m, d, w;
  cin >> m >> d >> w;
  w /= __gcd(d - 1, w);
  int val = min(m, d) - 1;  
  auto f = [] (long long x) {
    return (x * (x - 1)) / 2;
  };
  long long ans = f((val / w) + 1) * ((val % w) + 1) + 
    f(val / w) * (w - (val % w) - 1);
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
