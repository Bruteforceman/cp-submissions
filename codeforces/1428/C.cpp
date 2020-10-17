#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int n = s.size();
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == 'A') {
        a += 1;
      } else {
        if(a > 0) {
          a -= 1;
        } else {
          b += 1;
        }
      }
    }
    cout << a + (b & 1) << "\n";
  }
  return 0;
}
