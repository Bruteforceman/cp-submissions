#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int maxv = 1000005;
vector <pair <int, int>> change[maxv];
int main() {
  int n, m;
  cin >> n >> m;
  vector <pair <int, int>> a (n), b (m);
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for(int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second; 
  }
  sort(b.begin(), b.end());
  vector <pair <int, int>> aux;
  for(int i = 0; i < m; i++) {
    while(!aux.empty() && b[i].second >= aux.back().second) {
      aux.pop_back();
    }
    aux.push_back(b[i]);
  }
  b = aux;
  int now = 0;
  vector <int> cur (n);
  for(auto i : a) {
    cur[now] = max(0, b[0].second - i.second + 1);
    for(int k = 0; k < b.size(); k++) {
      int x = max(0, b[k].first - i.first + 1);
      int y = k + 1 < b.size() ? b[k + 1].second : -1;
      y = max(0, y - i.second + 1);
      change[x].emplace_back(now, y);
    }
    ++now;
  }
  priority_queue <pair <int, int>> Q;
  for(int i = 0; i < n; i++) Q.emplace(cur[i], i);
  int ans = INT_MAX;
  for(int i = 0; i < maxv; i++) {
    for(auto j : change[i]) {
      if(cur[j.first] > j.second) {
        Q.emplace(j.second, j.first);
        cur[j.first] = j.second;
      }
    }
    while(!Q.empty() && cur[Q.top().second] != Q.top().first) {
      Q.pop();
    }
    ans = min(ans, i + Q.top().first);
  }
  cout << ans << endl;
}
