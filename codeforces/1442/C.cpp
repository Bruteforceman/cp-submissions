#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 998244353;
const int logn = 30;
const int inf = 1e9;
int dp[logn][maxn];
vector <pair <int, int>> g[maxn];
vector <pair <int, int>> path[2][maxn];
int n, m;

int dist[2][maxn];
int d[2][maxn];
bool vis[2][maxn];

pair <int, int> solver() {
  for(int i = 1; i <= n; i++) {
    dist[0][i] = dist[1][i] = inf;
    vis[0][i] = vis[1][i] = false;
  }
  deque <pair <int, int>> Q;
  Q.emplace_back(0, 1);
  dist[0][1] = 0;
  while(not Q.empty()) {
    int cnt = Q.front().first;
    int node = Q.front().second;
    Q.pop_front();
    if(vis[cnt][node]) continue;
    vis[cnt][node] = true;
    for(auto i : g[node]) {
      int nodeU = i.first;
      int cntU = i.second;
      int cost = (i.second ^ cnt);
      if(dist[cntU][nodeU] > dist[cnt][node] + cost) {
        dist[cntU][nodeU] = dist[cnt][node] + cost;
        if(cost == 0) Q.emplace_front(cntU, nodeU);
        else Q.emplace_back(cntU, nodeU);
      }
    }
  }
  for(int node = 1; node <= n; node++) {
    for(int cnt = 0; cnt <= 1; cnt++) {
      for(auto i : g[node]) {
        int nodeU = i.first;
        int cntU = i.second;
        int cost = (i.second ^ cnt);
        if(dist[cntU][nodeU] == dist[cnt][node] + cost) {
          path[cnt][node].emplace_back(cntU, nodeU);
        }
      }
    }
  }
  memset(d, -1, sizeof d);
  queue <pair <int, int>> U;
  U.emplace(0, 1);
  d[0][1] = 0;
  while(not U.empty()) {
    auto x = U.front();
    U.pop();
    for(auto y : path[x.first][x.second]) {
      if(d[y.first][y.second] == -1) {
        d[y.first][y.second] = d[x.first][x.second] + 1;
        U.push(y);
      }
    }
  }
  long long ans = 1;
  int opt = min(dist[0][n], dist[1][n]);
  int shortest = inf;
  if(opt == dist[0][n]) shortest = min(shortest, d[0][n]);
  if(opt == dist[1][n]) shortest = min(shortest, d[1][n]);
  for(int i = 1; i <= opt; i++) ans = (2LL * ans) % mod;
  ans = (ans + shortest + mod - 1) % mod;
  return make_pair(opt, (int) ans);
}
int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    g[p].emplace_back(q, 0);
    g[q].emplace_back(p, 1);
  }
  memset(dp, -1, sizeof dp);
  queue <pair <int, int>> Q;
  Q.emplace(0, 1);
  dp[0][1] = 0;
  while(not Q.empty()) {
    int cnt = Q.front().first;
    int node = Q.front().second;
    Q.pop();
    for(auto i : g[node]) {
      int cntU = cnt + (i.second ^ (cnt % 2));
      int nodeU = i.first;
      if(cntU < logn && dp[cntU][nodeU] == -1) {
        dp[cntU][nodeU] = 1 + dp[cnt][node]; 
        Q.emplace(cntU, nodeU);
      }
    } 
  }
  auto val = solver();
  if(val.first >= logn) {
    printf("%d\n", val.second);
    exit(0);
  }
  long long ans = LLONG_MAX;
  for(int i = 0; i < logn; i++) {
    if(dp[i][n] != -1) {
      ans = min(ans, (1LL << i) - 1 + dp[i][n]);
    }
  }
  ans %= mod;
  printf("%lld\n", ans);
  return 0;
}
