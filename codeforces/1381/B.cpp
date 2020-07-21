#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int opt = 0;
  vector <int> peak;
  for(int i = 0; i < n + n; i++) {
    int x;
    cin >> x;
    opt = max(opt, x);
    if(opt == x) {
      peak.push_back(i);
    }
  }
  peak.push_back(2 * n);
  bitset <4005> dp;
  dp[0] = 1;
  for(int i = 1; i < peak.size(); i++) {
    dp |= dp << (peak[i] - peak[i - 1]);
  }
  if(dp[n]) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) solve(); 
  return 0;
}
