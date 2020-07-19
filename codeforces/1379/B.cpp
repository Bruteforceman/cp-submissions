#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long l, r, m;
  cin >> l >> r >> m;
  long long low = max(1LL, m - (r - l));
  long long high = m + (r - l);
  for(int a = l; a <= r; a++) {
    long long na = (high / a) * a;
    if(low <= na) {
      long long diff = m - na;
      long long b = r;
      long long c = r - abs(diff);
      if(diff < 0) swap(b, c);
      cout << a << " " << b << " " << c << endl;
      return ;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
