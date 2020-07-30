#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++) s += '9';
    int start = (3 * n) / 4;
    for(int i = start; i < s.size(); i++) s[i] = '8';
    cout << s << endl;
  }
}
