#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const int mod = 998244353;
int n, m;
char s[maxn];
struct data {
  long long dp[2][2];
} t[maxn * 4];
int cnt[100];
long long dp[1000];

long long getCount(int l, int r) {
  if(l > r) return 1;
  string txt = "#";
  for(int i = l; i <= r; i++) txt += s[i];
  dp[0] = 1;
  for(int i = 1; i <= r - l + 1; i++) {
    dp[i] = dp[i - 1] * cnt[txt[i] - '0'];
    dp[i] %= mod;
    if(i > 1) {
      int val = 10 * (txt[i - 1] - '0') + (txt[i] - '0');
      if(val > 9) {
        dp[i] += dp[i - 2] * cnt[val];
      }
    }
    dp[i] %= mod;
  }
  return dp[r - l + 1];
}
data merge(data a, data b, int val) {
  data ans;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      ans.dp[i][j] = 0;
      if (val > 9) {
        ans.dp[i][j] += (a.dp[i][0] * b.dp[0][j] % mod) * cnt[val];
        ans.dp[i][j] %= mod;
      }
      ans.dp[i][j] += a.dp[i][1] * b.dp[1][j];
      ans.dp[i][j] %= mod;
    }
  }
  return ans;
}
void update(int x, int d, int c = 1, int b = 1, int e = n) {
  if(b == e) {
    t[c].dp[0][0] = 1;
    t[c].dp[0][1] = t[c].dp[1][0] = 0;
    t[c].dp[1][1] = cnt[d];
    return ;
  }
  int m = (b + e) >> 1;
  int l = c << 1;
  int r = l + 1;
  if(x <= m) update(x, d, l, b, m);
  else update(x, d, r, m + 1, e);
  int val = 10 * (s[m] - '0') + (s[m + 1] - '0');
  if(e - b + 1 >= 4) {
    t[c] = merge(t[l], t[r], val);
  } else {
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        t[c].dp[i][j] = getCount(b + (i == 0), e - (j == 0));
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  scanf("%s", s + 1);
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      cnt[i + j] += 1;
    }
  }
  for(int i = 1; i <= n; i++) {
    update(i, s[i] - '0');
  }
  for(int i = 1; i <= m; i++) {
    int x, d;
    scanf("%d %d", &x, &d);
    s[x] = d + '0';
    update(x, d);
    printf("%lld\n", t[1].dp[1][1]);
  }
  return 0;
}
