#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  map <int, vector <int>> cont;
  for(int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cont[x].push_back(i);
  }
  vector <int> can (n + 1, INT_MAX);
  for(auto i : cont) {
    vector <int> v = i.second;
    v.insert(v.begin(), -1);
    v.insert(v.end(), n);
    int opt = 0;
    for(int j = 1; j < v.size(); j++) {
      int free = v[j] - v[j - 1] - 1;
      opt = max(opt, free + 1);
    }
    can[opt] = min(can[opt], i.first);
  }
  for(int i = 1; i <= n; i++) {
    can[i] = min(can[i - 1], can[i]);
    if(can[i] < INT_MAX) printf("%d ", can[i]);
    else printf("-1 ");
  }
  printf("\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}
