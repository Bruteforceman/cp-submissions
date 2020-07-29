#include <bits/stdc++.h>
using namespace std;
int solve(string &s, char p, char q) {
  char cur = p;
  int ans = 0;
  for(char i : s) {
    if(i == cur) {
      ++ans;
      cur = (cur == p) ? q : p;  
    }
  }
  if(p == q) return ans;
  else return (ans / 2) * 2; 
}
int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int ans = 0;
    for(char i = '0'; i <= '9'; i++) {
      for(char j = '0'; j <= '9'; j++) {
        ans = max(ans, solve(s, i, j));
      }
    }
    cout << (s.size() - ans) << endl;
  }
  return 0;
}
