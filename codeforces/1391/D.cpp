#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e6 + 5;
vector <vector <int>> v;
int n, m;
vector <int> a;
int mem[8][maxn];

int good(int val) {
  for(int i = 1; i < n; i++) {
    int p = ((val >> (i - 1)) & 1);
    int q = ((val >> i) & 1);
    if(p == q) return false;
  }
  return true;
}
int dp(int cur, int mask) {
  if(cur == m) return 0; 
  int &ans = mem[mask][cur];
  if(ans != -1) return ans;
  ans = n * m;
  for(int i = 0; i < 8; i++) {
    if(good(mask ^ i)) {
      ans = min(ans, dp(cur + 1, i) + __builtin_popcount(i ^ a[cur]));
    }
  }
  return ans;
}
int main() {
  cin >> n >> m;
  bool inv = false;
  if(n > m) {
    inv = true;
    v = vector <vector <int>> (m, vector <int> (n, 0));
  } else {
    v = vector <vector <int>> (n, vector <int> (m, 0));
  }
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < m; j++) {
      if(inv) v[j][i] = s[j] - '0';
      else v[i][j] = s[j] - '0';
    }
  }
  if(min(n, m) >= 4) {
    cout << -1 << endl;
    exit(0);
  }
  if(inv) swap(n, m);
  a.resize(m);
  for(int i = 0; i < m; i++) {
    int mask = 0;
    for(int j = 0; j < n; j++) {
      if(v[j][i]) mask |= 1 << j;
    }
    a[i] = mask;
  }
  memset(mem, -1, sizeof mem);
  int ans = n * m;
  for(int i = 0; i < 8; i++) ans = min(ans, dp(0, i));
  cout << ans << endl;
}
