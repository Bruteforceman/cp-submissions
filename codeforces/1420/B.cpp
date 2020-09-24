#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    map <int, int> cnt;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      int cur = 1, msb = 0;
      while(cur * 2 <= x) {
        cur *= 2;
        ++msb;
      }
      cnt[msb] += 1;
    }
    long long ans = 0;
    for(auto i : cnt) {
      ans += (1LL * i.second * (i.second - 1)) / 2;
    }
    cout << ans << endl;
  }
  return 0;
}
