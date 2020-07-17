#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector <int> g[maxn];
int deg[maxn], cnt[maxn];
bool del[maxn];

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i <= n; i++) {
    g[i].clear();
    deg[i] = del[i] = cnt[i] = 0;
  }
  for(int i = 1; i < n; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    g[p].push_back(q);
    g[q].push_back(p);
    deg[p] += 1;
    deg[q] += 1;
  }
  if(k == 1) {
    printf("%d\n", n - 1);
    return ;
  }
  int ans = 0;
  set <pair <int, int>> Q;
  for(int i = 1; i <= n; i++) {
    for(int j : g[i]) {
      if(deg[j] == 1) ++cnt[i];
    }
    Q.insert(make_pair(cnt[i], i));
  }
  while(true) {
    int x = Q.rbegin() -> second;
    Q.erase(make_pair(cnt[x], x));
    if(cnt[x] < k) break;

    ans += cnt[x] / k;
    int total = k * (cnt[x] / k);
    deg[x] -= total;
    cnt[x] -= total;
    for(auto i : g[x]) {
      if(del[i] || total <= 0) continue;
      if(deg[i] == 1) {
        del[i] = true;
        --total;
      }
    }
    if(deg[x] == 1) for(int i : g[x]) {
      if(del[i]) continue;
      Q.erase(make_pair(cnt[i], i));
      cnt[i] += 1;
      Q.insert(make_pair(cnt[i], i));
    }
    Q.insert(make_pair(cnt[x], x));
  }
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
  return 0;
}
