#include <bits/stdc++.h>
using namespace std;
const int maxv = 2e5;
int p[maxv + 10];
vector <int> v[maxv + 10];
int main() {
  for(int i = 1; i <= maxv; i++) p[i] = i;
  for(int i = 2; i <= maxv; i++) {
    if(p[i] != i) continue;
    for(int j = i + i; j <= maxv; j += i) {
      p[j] = i;
    }
  }
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    while(x > 1) {
      int y = p[x];
      int cnt = 0;
      while(x % y == 0) {
        x /= y;
        ++cnt;
      }
      v[y].push_back(cnt);
    }
  }
  long long ans = 1;
  for(int i = 1; i <= maxv; i++) {
    sort(v[i].begin(), v[i].end());
    if(v[i].empty()) continue;
    int pw = 0;
    if(v[i].size() == n) {
      pw = v[i][1];
    } else if (v[i].size() == n - 1) {
      pw = v[i][0];
    }
    while(pw--) {
      ans *= i;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
