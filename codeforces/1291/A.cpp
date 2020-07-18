#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    int n;
    cin >> n >> s;
    while(s.size() && (s.back() - '0') % 2 == 0) s.pop_back();
    int sum = 0;
    for(int i = 0; i < s.size(); i++) sum += s[i] - '0';
    if(sum % 2 == 1) {
      bool done = false;
      for(int i = int(s.size()) - 2; i >= 0; i--) {
        if((s[i] - '0') % 2 == 1) {
          s.erase(s.begin() + i);
          done = true;
          break;
        }
      }
      if(s[0] == '0') done = false;
      cout << (done ? s : "-1") << endl;
    } else cout << (s.size() ? s : "-1") << endl;
  }
  return 0;
}
