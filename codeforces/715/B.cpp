#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16;
const int maxn = 1e3 + 10;
const int maxm = 1e4 + 10;
int l[maxm], r[maxm], w[maxm];
vector <int> g[maxn];
int par[maxn][maxm];
long long dp[maxn][maxn];
struct node {
  int vertex, edge;
  long long dist;
  node (int vertex, int edge, long long dist) : vertex(vertex), edge(edge), dist(dist) {}
  node () {}
  bool operator < (node other) const {
    return dist > other.dist;
  }
};
int main() {
  int n, m, L, s, t;
  scanf("%d %d %d %d %d", &n, &m, &L, &s, &t);
  for(int i = 1; i <= m; i++) {
    scanf("%d %d %d", &l[i], &r[i], &w[i]);
    g[l[i]].push_back(i);
    g[r[i]].push_back(i);
  }
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      dp[i][j] = inf;
    }
  }
  priority_queue <node> Q;
  Q.emplace(s, 0, 0);
  dp[s][0] = 0;
  while(!Q.empty()) {
    node x = Q.top();
    Q.pop();
    if(dp[x.vertex][x.edge] != x.dist || x.edge == n) continue;
    for(auto e : g[x.vertex]) {
      int y = l[e] ^ r[e] ^ x.vertex;
      if(x.dist + max(1, w[e]) < dp[y][x.edge + (w[e] == 0)]) {
        dp[y][x.edge + (w[e] == 0)] = x.dist + max(1, w[e]);
        par[y][x.edge + (w[e] == 0)] = e;
        Q.emplace(y, x.edge + (w[e] == 0), x.dist + max(1, w[e]));
      }
    }
  }
  int edge = 0;
  int cur = t;
  while(edge < n && dp[cur][edge] > L) ++edge;
  if (edge >= n || (edge == 0 && dp[cur][edge] != L)) {
    puts("NO");
    exit(0);
  }
  long long add = L - dp[cur][edge];
  while(cur != s) {
    int e = par[cur][edge];
    int next = l[e] ^ r[e] ^ cur;
    if(w[e] == 0) {
      --edge;
      w[e] = 1;
      w[e] += add;
      add = 0;
    }
    cur = next;
  }
  puts("YES");
  for(int i = 1; i <= m; i++) {
    if(w[i] == 0) {
      w[i] = L + 1;
    }
    printf("%d %d %d\n", l[i], r[i], w[i]);
  }
  return 0;
}
