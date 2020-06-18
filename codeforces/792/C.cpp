#include <bits/stdc++.h>
using namespace std;
string removeOne(string s) {
  int n = s.size();
  int total = 0;
  vector <bool> del(n, false);
  for(char i : s) {
    total += i - '0';
    total %= 3;
  }
  for(int i = n - 1; total != 0 && i >= 0; i--) {
    if((s[i] - '0') % 3 == total) {
      total = 0;
      del[i] = true;
      break;
    }
  }
  bool start = false;
  string t = "";
  for(int i = 0; i < n; i++) {
    if(del[i]) continue;
    if(s[i] != '0') start = true;
    if(start) t += s[i];
  } 
  if(total == 0) return t;
  else return "";
}
string removeTwo(string s) {
  int n = s.size();
  int total = 0;
  vector <bool> del(n, false);
  for(char i : s) {
    total += i - '0';
    total %= 3;
  }
  for(int i = n - 1; total != 0 && i >= 0; i--) {
    if((s[i] - '0') % 3 != 0) {
      del[i] = true;
      total = (9 + total - (s[i] - '0')) % 3;
    }
  } 
  bool start = false;
  string t = "";
  for(int i = 0; i < n; i++) {
    if(del[i]) continue;
    if(s[i] != '0') start = true;
    if(start) t += s[i];
  } 
  if(total == 0) return t;
  else return "";
}
int main() {
  string s;
  cin >> s;
  int n = s.size();
  string t = max(removeOne(s), removeTwo(s), [] (auto i, auto j) {
      return i.size() < j.size(); } );
  if(t.empty()) {
    for(int i = 0; i < n; i++) if (s[i] == '0') { t = "0"; break; }
  }
  if(t.empty()) cout << -1 << endl;
  else cout << t << endl;
}
