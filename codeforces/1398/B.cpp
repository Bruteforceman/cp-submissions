#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    vector <int> v;
    int cnt = 0;
    for(char i : s) {
      if(i == '1') {
        ++cnt;
      } else {
        v.push_back(cnt);
        cnt = 0;
      }
    }
    if(cnt) v.push_back(cnt);
    sort(v.begin(), v.end(), greater <int> ());
    int ans = 0;
    for(int i = 0; i < v.size(); i++) {
      if(i % 2 == 0) ans += v[i];
    }
    cout << ans << endl;
  }
  return 0;
}
