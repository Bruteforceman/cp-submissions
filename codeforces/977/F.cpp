#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int nxt[maxn], dp[maxn];

int main() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map <int, int> pos;
  int opt = 0;
  for(int i = n; i >= 1; i--) {
    if(pos.find(a[i] + 1) == pos.end()) {
      nxt[i] = n + 1;
      dp[i] = 1;
    } else {
      nxt[i] = pos[a[i] + 1];
      dp[i] = 1 + dp[nxt[i]];
    }
    pos[a[i]] = i;
    opt = max(opt, dp[i]);
  }
  cout << opt << endl;
  for(int i = 1; i <= n; i++) {
    if(dp[i] == opt) {
      int cur = i;
      while(cur <= n) {
        cout << cur << " ";
        cur = nxt[cur];
      }
      break;
    }
  }
  return 0;
}
