#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector <int> v;
    for(int i = 0; i < n; i++) {
      if(i > 0) {
        v.push_back(i - 1);
      }
      v.push_back(i);
      if(s[i] == t[n - i - 1]) {
        v.push_back(0);
      }
    }
    cout << v.size() << " " ;
    for(auto i : v) cout << i + 1 << " ";
    cout << endl;
  }
  return 0;
}
