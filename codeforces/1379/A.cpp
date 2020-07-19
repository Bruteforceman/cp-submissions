#include <bits/stdc++.h>
using namespace std;
int occur(string s, string t) {
  int ans = 0;
  for(int i = 0; i + t.size() - 1 < s.size(); i++) {
    bool good = true;
    for(int j = 0; j < t.size(); j++) {
      if(s[i + j] != t[j]) good = false; 
    }
    ans += good;
  }
  return ans;
}
void solve() {
  int n;
  string s;
  cin >> n >> s;
  string t = "abacaba";
  for(int i = 0; i + t.size() - 1 < s.size(); i++) {
    string p = s;
    bool good = true;
    for(int j = 0; j < t.size(); j++) {
      if(s[i + j] != '?' && s[i + j] != t[j]) good = false;
      p[i + j] = t[j];
    }
    if(good) {
      for(int j = 0; j < s.size(); j++) if(p[j] == '?') p[j] = 'z';
      if(occur(p, t) == 1) {
        cout << "YES" << endl;
        cout << p << endl;
        return ;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
