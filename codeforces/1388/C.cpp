#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector <int> g[maxn];
int p[maxn];
int h[maxn];
long long sub[maxn], good[maxn], bad[maxn];
bool ans;

void dfs(int x, int par) {
  sub[x] = p[x];
  for(int i : g[x]) {
    if(i != par) {
      dfs(i, x);
      sub[x] += sub[i];
    }
  }
  if(abs(h[x] + sub[x]) % 2 == 1) ans = false;
  good[x] = (sub[x] + h[x]) / 2;
  bad[x] = (sub[x] - h[x]) / 2;
  if(bad[x] < 0 || good[x] < 0) ans = false;
  long long total = 0;
  for(int i : g[x]) {
    if(i != par) {
      total += bad[i];
    }
  }
  if(total < bad[x] - p[x]) {
    ans = false;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    ans = true;
    dfs(1, 0);
    if(ans) puts("YES");
    else puts("NO");
  }
  return 0;
}
