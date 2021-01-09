#include <bits/stdc++.h>
using namespace std;
long long n;

long long goDown(long long x, char c) {
  long long pw = 1;
  long long tmp = x;
  while(tmp % 2 == 0) {
    tmp /= 2;
    pw *= 2;
  }
  if(pw == 1) return x;
  else if (c == 'L') return x - pw / 2;
  else return x + pw / 2;
}
long long goUp(long long x) {
  long long pw = 1;
  long long tmp = x;
  while(tmp % 2 == 0) {
    tmp /= 2;
    pw *= 2;
  }
  if(tmp % 4 == 1) return x + pw;
  else return x - pw;
}
int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);
  int q;
  cin >> n >> q;
  for(int i = 0; i < q; i++) {
    string s;
    long long u;
    cin >> u >> s;
    for(auto j : s) {
      long long v;
      if(j == 'U') v = goUp(u);
      else v = goDown(u, j);
      if(1 <= v && v <= n) u = v;
    }
    cout << u << "\n";
  }
  return 0;
}

