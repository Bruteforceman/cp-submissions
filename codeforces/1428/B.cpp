#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    string s;
    int n;
    cin >> n;
    cin >> s;
    int cnt1 = count(s.begin(), s.end(), '>');
    int cnt2 = count(s.begin(), s.end(), '<');
    int ans = 0;
    for(int i = 0; i < n; i++) {
      char p = s[i];
      char q = s[(i + n - 1) % n];
      if(p == '-' || q == '-') ++ans;
      else if (cnt1 == 0 || cnt2 == 0) ++ans;
    }
    cout << ans << "\n";
  }
  return 0;
}
