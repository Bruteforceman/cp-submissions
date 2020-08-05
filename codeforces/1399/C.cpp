#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector <int> cnt (2 * n + 1);
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x] += 1;
    }
    int ans = 0;
    for(int i = 1; i <= n + n; i++) {
      int team = 0;
      for(int j = 0; j <= n + n; j++) {
        if(j * 2 < i) {
          team += min(cnt[j], cnt[i - j]);
        }
      }
      if(i % 2 == 0) team += cnt[i / 2] / 2;
      ans = max(ans, team);
    }
    cout << ans << endl;
  }
  return 0;
}
