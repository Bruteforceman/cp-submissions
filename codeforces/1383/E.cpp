#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1000000000 + 7;
int dp[2][maxn], nxt[2][maxn];
int a[maxn];
int len[maxn];
int n;

int main() {
  string s;
  cin >> s;
  n = s.size();
  for(int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
  nxt[0][n + 1] = nxt[1][n + 1] = n + 1;
  // dp[0][n + 1] = dp[1][n + 1] = 1;
  for(int i = n; i >= 1; i--) {
    for(int bit = 0; bit <= 1; bit++) {
      nxt[bit][i] = nxt[bit][i + 1];
    }
    nxt[a[i]][i] = i;
  }
  int sum = 0;
  long long total = 1;
  len[0] = 1;
  int cnt = 0;
  for(int i = n; i >= 1; i--) {
    if(a[i] == 0) {
      ++cnt;
    } else break;
  }
  for(int i = n; i >= 1; i--) {
    if(a[i] == 0) {
      int var = nxt[1][i] - i;
      total += (mod - len[var]);
      len[var] = dp[1][nxt[1][i]];
      if(var <= cnt) len[var] = (len[var] + 1) % mod;
      total += len[var];
      total %= mod;
    }
    dp[0][i] = total;
    if(a[i] == 1) {
      sum += total;
      sum %= mod;
    }
    dp[1][i] = sum;
  }
  if(nxt[1][1] <= n) 
    cout << (1LL * dp[1][nxt[1][1]] * nxt[1][1]) % mod << endl;
  else 
    cout << n << endl;
  return 0;
}
