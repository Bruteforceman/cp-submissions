#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector <int> g[maxn];
vector <int> t[maxn];
int col[maxn];
int sub[maxn], disc[maxn], dp[maxn], euler[maxn];
int ord[maxn];
int n, cur;
vector <int> back[maxn];
bool bad[maxn];

bool dfs(int x) {
  bool ans = true;
  disc[x] = ++cur;
  euler[cur] = x;
  col[x] = -1;
  dp[x] = disc[x];
  for(int i : g[x]) {
    if(col[i] == 0) {
      t[x].push_back(i);
      ans &= dfs(i);
      dp[x] = min(dp[x], dp[i]);
    } else if (col[i] == 1) {
      return false;
    } else {
      sub[i] -= 1;
      sub[x] += 1;
      dp[x] = min(dp[x], disc[i]);
    }
  }
  col[x] = 1;
  return ans;
}
void subtree(int x, int par) {
  for(auto i : t[x]) {
    if(i != par) {
      subtree(i, x);
      sub[x] += sub[i];
    }
  }
}

bool check(int x) {
  cur = 0;
  for(int i = 1; i <= n; i++) {
    t[i].clear();
    back[i].clear();
    col[i] = 0;
    sub[i] = 0;
    bad[i] = false;
  }
  if(!dfs(x)) return false;
  subtree(x, 0);
  for(int i = 1; i <= n; i++) {
    if(sub[i] == 1) {
      back[euler[dp[i]]].push_back(i);
    }
  }
  queue <int> Q;
  for(int i = 1; i <= n; i++) {
    if(sub[i] > 1) {
      Q.push(i);
      bad[i] = true;
    }
  }
  while(!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for(auto i : back[x]) {
      if(bad[i] == false) {
        bad[i] = true;
        Q.push(i);
      }
    }
  }
  vector <int> v;
  for(int i = 1; i <= n; i++) if(bad[i] == false) v.push_back(i);
  if(v.size() * 10 >= 2 * n) {
    for(auto i : v) cout << i << " ";
    cout << endl;
  } else cout << -1 << endl;
  return true;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
      g[i].clear();
      ord[i] = i;
    }
    for(int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
    }
    random_shuffle(ord + 1, ord + n + 1);
    bool found = false;
    for(int i = 1; i <= n && i <= 50; i++) {
      if(check(ord[i])) {
        found = true;
        break;
      }
    }
    if(!found) cout << "-1" << endl;
  }
  return 0;
}
