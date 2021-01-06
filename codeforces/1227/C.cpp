#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string t;
  for(int i = 0; i < k - 1; i++) {
    t += "()";
  }
  int rem = n - t.size();
  if(rem > 0) t += string (rem / 2, '(') + string(rem / 2, ')');
  cout << n << endl;
  for(int i = 0; i < n; i++) {
    int r = i;
    for(int j = i; j < n; j++) {
      if(s[j] == t[i]) {
        r = j;
        break;
      }
    }
    cout << i + 1 << " " << r + 1 << endl;
    reverse(s.begin() + i, s.begin() + r + 1);
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}
