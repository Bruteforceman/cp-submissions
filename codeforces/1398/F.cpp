#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char s[maxn];
int dp[maxn];
int par[maxn];
int sub[maxn];
int opt[maxn];

int root(int x) {
  if(par[x] == x) return x;
  return par[x] = root(par[x]);
}
void join(int x, int y) {
  x = root(x);
  y = root(y);
  if(x != y) {
    if(sub[x] > sub[y]) swap(x, y);
    par[x] = y;
    sub[y] += sub[x];
    opt[y] = max(opt[y], opt[x]);
  }
}
int nextVal(int x) {
  return opt[root(x)];
}
int ord[maxn];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  for(int i = 1; i <= n + 1; i++) {
    par[i] = i;
    sub[i] = 1;
    opt[i] = i;
  }
  int cnt[] = {0, 0};
  int r = n;
  for(int i = n; i >= 1; i--) {
    if(s[i] != '?') cnt[s[i] - '0'] += 1;
    while(r > i && cnt[1] > 0 && cnt[0] > 0) {
      if(s[r] != '?') cnt[s[r] - '0'] -= 1;
      r -= 1;
    }
    dp[i] = r - i + 1;
    ord[i] = i;
  }
  sort(ord + 1, ord + n + 1, [&] (int i, int j) {
      return dp[i] < dp[j]; } );
  int pt = 1;
  for(int i = 1; i <= n; i++) {
    while(pt <= n && dp[ord[pt]] < i) {
      join(ord[pt], ord[pt] + 1);
      ++pt;
    }
    int ans = 0;
    int cur = 1;
    while(nextVal(cur) <= n) {
      ++ans;
      cur = nextVal(cur);
      cur += i;
    }
    printf("%d ", ans);
  }
  puts("");
  return 0; 
}
