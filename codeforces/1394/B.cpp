#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int bad[10][10][10][10];
int n, m, k;
vector <pair <int, int>> g[maxn];
int a[10][maxn];
int ans;
int sol[10];
void solve(int cur) {
  if(cur == k + 1) {
    ans += 1;
    return ;
  }
  for(int i = 1; i <= cur; i++) {
    sol[cur] = i;
    bool good = true;
    for(int j = 1; j <= cur; j++) {
      if(bad[j][sol[j]][cur][sol[cur]]) {
        good = false;
        break;
      }
    }
    if(good) solve(cur + 1);
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= m; i++) {
    int p, q, r;
    scanf("%d %d %d", &p, &q, &r);
    g[p].emplace_back(r, q);
  }
  for(int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());
    int deg = g[i].size();
    for(int j = 1; j <= deg; j++) {
      if((a[deg][g[i][j - 1].second] >> j) & 1) {
        bad[deg][j][deg][j] = 1;
      }
      a[deg][g[i][j - 1].second] |= 1 << j;
    }
  }

  for(int i = 1; i <= n; i++) {
    vector <pair <int, int>> can;
    for(int x = 1; x <= k; x++) {
      for(int y = 1; y <= x; y++) {
        if((a[x][i] >> y) & 1) {
          can.emplace_back(x, y);
        }
      }
    }
    for(int x = 0; x < can.size(); x++) {
      for(int y = 0; y < can.size(); y++) {
        if(x == y) continue;
        bad[can[x].first][can[x].second][can[y].first][can[y].second] = 1;
      }
    }
  }
  solve(1);
  printf("%d\n", ans);
  return 0;
}
