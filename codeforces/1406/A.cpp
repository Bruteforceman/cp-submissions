#include <bits/stdc++.h>
using namespace std;
int cnt[111];
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x] += 1;
    }
    int ans = 0;
    for(int x = 0; x < 2; x++) {
      int cur = 0;
      while(cnt[cur] > 0) {
        cnt[cur] -= 1;
        ++cur;
      }
      ans += cur;
    }
    cout << ans << endl;
  }
}
