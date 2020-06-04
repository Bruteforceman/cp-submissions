#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int t[maxn];
vector <int> g[maxn];
bool done[maxn];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    g[p].push_back(q);
    g[q].push_back(p);
  }
  vector <pair <int, int>> v;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    v.emplace_back(t[i], i);
  }
  sort(v.begin(), v.end());
  for(auto i : v) {
    int x = i.second;
    set <int> s;
    for(auto j : g[x]) {
      if(done[j]) {
        s.insert(t[j]);
      }
    }
    int cnt = 1;
    while(s.count(cnt)) ++cnt;
    if(cnt != t[x]) {
      printf("-1\n");
      exit(0);
    }
    done[x] = true;
  }
  for(auto i : v) printf("%d ", i.second);
  printf("\n");
  return 0;
}
