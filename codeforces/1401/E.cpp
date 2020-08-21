#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int t[maxn + 5];
vector <int> start[maxn + 5], fin[maxn + 5];
vector <pair <int, int>> line[maxn + 5];

void update(int x, int val) {
  x += 1;
  for(int i = x; i <= maxn + 1; i += i & (-i)) {
    t[i] += val;
  }
}
int query(int x) {
  x += 1;
  int sum = 0;
  for(int i = x; i > 0; i -= i & (-i)) {
    sum += t[i];
  }
  return sum;
}
int n, m;
int y[maxn], lx[maxn], rx[maxn];
int x[maxn], ly[maxn], ry[maxn];

pair <long long, long long> solve(bool extra) {
  for(int i = 1; i <= n; i++) {
    line[y[i]].emplace_back(lx[i], rx[i]);
  }
  for(int i = 1; i <= m; i++) {
    start[ly[i]].emplace_back(x[i]);
    fin[ry[i]].emplace_back(x[i]);
  }
  memset(t, 0, sizeof t);
  long long node = 0;
  long long edge = 0;
  for(int i = 0; i <= maxn; i++) {
    for(auto j : start[i]) {
      update(j, 1);
    }
    for(auto j : line[i]) {
      if(not extra) {
        node += 2 + query(j.second - 1) - query(j.first);
      } else {
        if(query(j.second) == query(j.second - 1)) ++node;
        if(query(j.first) == query(j.first - 1)) ++node;
      }
      edge += 1 + query(j.second - 1) - query(j.first);
    }
    for(auto j : fin[i]) {
      update(j, -1);
    }
    start[i].clear();
    fin[i].clear();
    line[i].clear();
  }
  return make_pair(node, edge);
}


int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d %d", y + i, lx + i, rx + i);
  }
  y[++n] = 0;
  lx[n] = 0; rx[n] = maxn;
  y[++n] = maxn;
  lx[n] = 0; rx[n] = maxn;

  for(int i = 1; i <= m; i++) {
    scanf("%d %d %d", x + i, ly + i, ry + i);
  }
  x[++m] = 0;
  ly[m] = 0; ry[m] = maxn;
  x[++m] = maxn;
  ly[m] = 0; ry[m] = maxn;

  auto p = solve(false);
  swap(n, m);
  for(int i = 1; i <= max(n, m); i++) {
    swap(x[i], y[i]);
    swap(lx[i], ly[i]);
    swap(rx[i], ry[i]);
  }
  auto q = solve(true);
  long long node = p.first + q.first;
  long long edge = p.second + q.second;
  cout << (1 - node + edge) << endl;
}
