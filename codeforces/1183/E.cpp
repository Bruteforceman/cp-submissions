#include <bits/stdc++.h>
using namespace std;
const int alpha = 26;
const int maxn = 111;

string s;
int nxt[alpha][maxn];
int n, k;
int cnt;

void backtrack(int cur, int len) {
  if(n - cur + 1 < len || cnt >= k) return ;
  if(len == 0) {
    ++cnt;
    return ;
  }
  for(int i = 0; i < alpha; i++) {
    int x = nxt[i][cur];
    if(x <= n) {
      backtrack(x, len - 1);
    }
  }
}

int main() {
  cin >> n >> k;
  cin >> s;
  s = "&" + s;
  int last[alpha];
  fill(last, last + alpha, n + 1);
  for(int i = n; i >= 0; i--) {
    for(int j = 0; j < alpha; j++) {
      nxt[j][i] = last[j];
    }
    if(i > 0) last[s[i] - 'a'] = i;
  }
  int ans = 0;
  for(int i = n; i >= 0; i--) {
    cnt = 0;
    backtrack(0, i);
    ans += (n - i) * cnt;
    k -= cnt;
  }
  if(k == 0) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}
