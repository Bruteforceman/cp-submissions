#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector <int> g[maxn];
int sub[maxn];
int dep[maxn];
int a[maxn];
vector <int> order;

void dfs(int x, int par) {
  sub[x] = 1;
  order.push_back(x);
  for(auto i : g[x]) {
    if(i != par) {
      dep[i] = 1 + dep[x];
      dfs(i, x);
      sub[x] += sub[i];
    }
  }
}
int centroid(int x, int par, int range) {
  for(auto i : g[x]) {
    if(i != par) {
      if(sub[i] > range) {
        return centroid(i, x, range);
      }
    }
  }
  return x;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    g[p].push_back(q);
    g[q].push_back(p);
  }
  dfs(1, 0);
  int c = centroid(1, 0, n / 2);
  order.clear();
  dep[c] = 0;
  dfs(c, 0);
  long long ans = 0;
  for(int i = 1; i <= n; i++) ans += 2 * dep[i];
  printf("%lld\n", ans);
  for(int i = 0; i < n; i++) {
    a[order[i]] = order[(i + (n / 2)) % n];
  }
  for(int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
}
