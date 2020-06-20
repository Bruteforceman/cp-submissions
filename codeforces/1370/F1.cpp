#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3;
vector <int> order;
vector <int> g[maxn];
void dfs(int x, int par) {
  for(int i : g[x]) {
    if(i != par) {
      dfs(i, x);
    }
  }
  order.push_back(x);
}
pair <int, int> query(vector <int> v) {
  cout << "? " << v.size();
  for(int i : v) {
    cout << " " << i;
  }
  cout << endl;
  pair <int, int> p;
  cin >> p.first >> p.second;
  return p;
}
void getAll(int x, int par, int dist, vector <int> &v) {
  if(dist == 0) v.push_back(x);
  for(auto i : g[x]) {
    if(i != par) {
      getAll(i, x, dist - 1, v);
    }
  }
}
void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) g[i].clear();
  order.clear();
  for(int i = 1; i < n; i++) {
    int p, q;
    cin >> p >> q;
    g[p].push_back(q);
    g[q].push_back(p);
  }
  vector <int> v;
  for(int i = 1; i <= n; i++) v.push_back(i);
  int root, dist;
  tie(root, dist) = query(v);
  dfs(root, 0);
  int l = 0, r = order.size() - 1;
  while(l < r) {
    int mid = (l + r) >> 1;
    v.clear();
    for(int i = 0; i <= mid; i++) {
      v.push_back(order[i]);
    }
    if(query(v).second != dist) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  root = order[l];
  v.clear();
  getAll(root, 0, dist, v);
  int another = query(v).first;
  cout << "! " << root << " " << another << endl;
  string check;
  cin >> check;
  assert(check == "Correct");
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
