#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 998244353;
int a[maxn], b[maxn], pos[maxn];

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  set <int> s;
  s.insert(0);
  s.insert(n + 1);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  for(int i = 1; i <= k; i++) {
    scanf("%d", &b[i]);
  }
  int ans = 1;
  for(int i = k; i >= 1; i--) {
    int x = pos[b[i]];
    int cnt = 0;
    if(not s.count(x - 1)) ++cnt;
    if(not s.count(x + 1)) ++cnt;
    ans = (ans * cnt) % mod;
    s.insert(x);
  }
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
  return 0;
}
