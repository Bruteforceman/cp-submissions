#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  vector <long long> pos, neg;
  for(int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if(x <= 0) neg.push_back(x);
    else pos.push_back(x);
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  vector <long long> canP, canN;
  for(int i = 0; i < pos.size(); i++) {
    if(i < 5 || pos.size() - i <= 5) canP.push_back(pos[i]);
  }
  for(int i = 0; i < neg.size(); i++) {
    if(i < 5 || neg.size() - i <= 5) canN.push_back(neg[i]);
  }
  auto add = [&] (vector <long long> v) {
    vector <pair <int, long long>> ret;
    ret.emplace_back(0, 1);
    for(int i = 0; i < v.size(); i++) {
      long long prod = 1;
      for(int j = i; j < v.size(); j++) {
        prod *= v[j];
        ret.emplace_back(j - i + 1, prod);
      }
    }
    return ret;
  };
  auto p1 = add(canP);
  auto p2 = add(canN);
  long long ans = LLONG_MIN;
  for(auto i : p1) for(auto j : p2) {
    if(i.first + j.first == 5) ans = max(ans, i.second * j.second);
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
}
