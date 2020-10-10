#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int lose = 0;
  int point = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'L') {
      ++lose;
    } else if (i > 0 && s[i - 1] == s[i]) {
      point += 2;
    } else {
      point += 1;
    }
  }
  bool start = false;
  int cnt = 0;
  vector <int> v;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'L') {
      ++cnt;
    } else {
      if(cnt > 0 && start) v.push_back(cnt);
      cnt = 0;
      start = true;
    }
  }
  if(point == 0 && k > 0) {
    point -= 1;
  }
  point += 2 * min(lose, k);
  sort(v.begin(), v.end());
  for(int i : v) {
    if(i <= k) {
      ++point;
      k -= i;
    }
  }
  cout << point << endl;
}
int main() {
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}
