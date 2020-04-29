#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long inf = 1e17;

struct Edge {
  int u, v, w; 
  Edge () {}
  Edge (int u, int v, int w) : u(u), v(v), w(w) {}
} e[maxn];
struct Node {
  int node;
  long long dist;
  Node () {}
  Node (int node, long long dist) : node(node), dist(dist) {}
  bool operator < (Node a) const {
    return dist > a.dist;
  }
};
int same[maxn], close[maxn];
long long dist[maxn], optDist[maxn];
int par[maxn];
int n, m;
bool special[maxn];
vector <int> g[maxn];
int cmp;

int root(int x) {
  if(par[x] == x) return x;
  else return par[x] = root(par[x]);
}
void join(int x, int y) {
  x = root(x);
  y = root(y);
  if(x != y) {
    par[x] = y;
    cmp -= 1;
  }
}
long long getClosest() {
    fill(dist, dist + n, inf);
    priority_queue <Node> t; 
    for(int i = 0; i < n; i++) {
      if(special[i]) {
        dist[i] = 0;
        same[i] = root(i);
        t.push(Node(i, 0));
      }
    }
    while(!t.empty()) {
      Node p = t.top(); t.pop();
      for(int i : g[p.node]) {
        int x = p.node ^ e[i].u ^ e[i].v;
        if(dist[x] > p.dist + e[i].w) {
          dist[x] = p.dist + e[i].w;
          same[x] = same[p.node];
          t.push( Node(x, dist[x]));
        }
      }
    }
    fill(close, close + n, -1);
    fill(optDist, optDist + m, inf);
    for(int i = 0; i < m; i++) {
      if(same[e[i].u] != same[e[i].v]) {
        long long d = dist[e[i].u] + dist[e[i].v] + e[i].w;
        int p = same[e[i].u];
        int q = same[e[i].v];
        if(d < optDist[p]) {
          optDist[p] = d;
          close[p] = q;
        }
        if(d < optDist[q]) {
          optDist[q] = d;
          close[q] = p;
        }
      }
    }
    long long add = 0;
    for(int i = 0; i < n; i++) {
      if(close[i] == -1) continue;
      if(special[i] && root(i) != root(close[i])) {
        join(i, close[i]);
        add += optDist[i];
      }
    }
    return add;
  }

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    e[i].u -= 1;
    e[i].v -= 1;
    g[e[i].u].push_back(i);
    g[e[i].v].push_back(i);
  }
  int k;
  scanf("%d", &k);
  for(int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    special[x - 1] = true;
  }
  fill(dist, dist + n, inf);
  priority_queue <Node> t; 
  t.emplace(0, 0);
  dist[0] = 0;
  while(!t.empty()) {
    Node p = t.top(); t.pop();
    for(int i : g[p.node]) {
      int x = p.node ^ e[i].u ^ e[i].v;
      if(dist[x] > p.dist + e[i].w) {
        dist[x] = p.dist + e[i].w;
        t.push( Node(x, dist[x]));
      }
    }
  }
  long long opt = inf;
  for(int i = 0; i < n; i++) {
    if(opt > dist[i] && special[i]) opt = dist[i];
  }
  for(int i = 0; i < n; i++) {
    par[i] = i ;
  }
  cmp = n;
  long long ans = opt;
  while(cmp > (n - k + 1)) {
    ans += getClosest();
  }
  printf("%lld\n", ans);
  return 0;
}
