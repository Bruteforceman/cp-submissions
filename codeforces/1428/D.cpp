#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 1e5 + 10;
int a[maxn];

int main() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector <pair <int, int>> v;
  for(int x = 2; x <= 3; x++) {
    stack <int> s;
    for(int i = n; i >= 1; i--) {
      if(0 < a[i] && a[i] < x) {
        s.push(i);
      } else if (a[i] == x) {
        if(s.empty()) {
          cout << -1 << endl;
          exit(0);
        } else {
          if(a[i] == 3 && a[s.top()] == 1) {
            v.emplace_back(s.top(), s.top());
          }
          a[s.top()] = 0;
          v.emplace_back(i, s.top());
          s.pop();
          if(a[i] == 3) s.push(i);
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(a[i] == 1) {
      v.emplace_back(i, i);
    }
  }
  if(v.size() > n) {
    cout << -1 << endl;
    exit(0);
  }
  vector <pair <int, int>> point;
  for(int i = 0; i < v.size(); i++) {
    point.emplace_back(n - i, v[i].first);
    if(v[i].first != v[i].second) {
      point.emplace_back(n - i, v[i].second);
    }
  }
  cout << point.size() << endl;
  for(auto i : point) {
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}
