#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf = 1e8;
int a[maxn];
int mem[4][maxn];
int n;
int start;
int good(int val) {
  if((val % 8) == 0 || (val % 8) == 7) return false;
  val /= 2;
  if(val == 0 || val == 7) return false;
  return true;
}
int dp(int mask, int cur) {
  if(cur == n) {
    return good(mask * 4 + start) ? 0 : inf;
  }
  int &ans = mem[mask][cur];
  if(ans != -1) return ans;
  ans = inf;
  for(int i = 0; i < 2; i++) {
    int nmask = (mask * 2 + i);
    if(nmask == 0 || nmask == 7) continue;
    ans = min(ans, dp(nmask % 4, cur + 1) + (i != a[cur]));
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) a[i] = (s[i] == 'L');
    if(n < 3) {
      cout << 0 << endl;
      continue;
    }
    int ans = inf;
    for(int i = 0; i < (1 << 2); i++) {
      int cnt = 0;
      for(int j = 0; j < 2; j++) {
        int bit = (i >> j) & 1;
        cnt += (bit != a[j ^ 1]);
      }
      for(int mask = 0; mask < 4; mask++) {
        for(int cur = 0; cur <= n; cur++) {
          mem[mask][cur] = -1;
        }
      }
      start = i;
      cnt += dp(start, 2);
      ans = min(ans, cnt);
    }
    cout << ans << "\n";
  }
  return 0;
}
