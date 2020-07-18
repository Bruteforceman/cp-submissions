#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 2.5e5 + 10;
vector <int> g[maxn];
int dep[maxn];
int par[maxn];
bool vis[maxn];
int n, k;
bool leaf[maxn];

void dfs(int x) {
  vis[x] = true;
  if(1LL * k * dep[x] >= n) {
    cout << "PATH" << endl;
    cout << dep[x] << endl;
    while(x != 1) {
      cout << x << " ";
      x = par[x];
    }
    cout << 1 << endl;
    exit(0);
  }
  int child = 0;
  for(int i : g[x]) {
    if(vis[i] == false) {
      dep[i] = 1 + dep[x];
      par[i] = x;
      child += 1;
      dfs(i);
    }
  }
  leaf[x] = (child == 0);
}
int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++) {
    int p, q;
    cin >> p >> q;
    g[p].push_back(q);
    g[q].push_back(p);
  }
  dep[1] = 1;
  dfs(1);
  cout << "CYCLES" << endl;
  for(int i = 1; i <= n; i++) {
    if(k == 0) break;
    if(leaf[i]) {
      k -= 1;
      vector <int> can;
      for(int j : g[i]) if(j != par[i]) can.push_back(j);
      int p = can[0], q = can[1];
      if(dep[p] > dep[q]) swap(p, q);
      if((dep[q] - dep[p] + 2) % 3 != 0) {
        cout << dep[q] - dep[p] + 2 << endl;
        int cur = q;
        cout << i << " ";
        while(cur != p) {
          cout << cur << " ";
          cur = par[cur];
        }
        cout << p << endl;
      } else {
        if((dep[i] - dep[p] + 1) % 3 == 0) swap(p, q);
        cout << dep[i] - dep[p] + 1 << endl;
        int cur = i;
        while(cur != p) {
          cout << cur << " ";
          cur = par[cur];
        }
        cout << p << endl;
      }
    }
  }
  return 0;
}
