#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector <int> start[2 * maxn], fin[2 * maxn];
void solve() {
  int n;
  scanf("%d", &n);
  vector <pair <int, int>> ranges;
  vector <int> add (2*n + 1, 0), first (2*n + 1, 0) ;
  map <int, int> cmp;
  for(int i = 0; i < n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    cmp[l]; cmp[r];
    ranges.emplace_back(l, r);
  }
  int idx = 0;
  for(auto &i : cmp) i.second = ++idx;
  for(auto &i : ranges) { 
    i.first = cmp[i.first];
    i.second = cmp[i.second];
    start[i.first].push_back(i.second);
    fin[i.second].push_back(i.first);
  }
  multiset <int> s;
  int segment = 0;
  for(int i = 1; i <= idx; i++) {
    for(int j : start[i]) {
      if(s.size() == 0) {
        segment += 1;
        first[i] = 1;
      } else if (s.size() == 1) {
        if(*s.begin() < i) add[*s.begin()] += 1;
        else first[i] = 0;
      }
      s.insert(i);
    }
    for(int j : fin[i]) {
      s.erase(s.find(j));
    }
    start[i].clear(); fin[i].clear();
  }
  int ans = 0;
  for(int i = 1; i <= idx; i++) {
    ans = max(ans, segment + add[i] - first[i]);
  }
  ans = min(ans, n - 1);
  printf("%d\n", ans);
  return ;
}
int main() {
  int t;
  scanf("%d", &t);
  for(int cs = 1; cs <= t; cs++) solve();
}
