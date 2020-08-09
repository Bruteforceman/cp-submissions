#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector <string> s (n);
    for(int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
      if(s[i][m - 1] == 'R') ++ans;
    }
    for(int i = 0; i < m - 1; i++) {
      if(s[n - 1][i] == 'D') ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}
