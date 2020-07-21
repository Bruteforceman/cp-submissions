#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  auto f = [] (char c, int inv) {
    if(inv) return (c == '0') ? '1' : '0';
    return c;
  };
  while(t--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector <int> v;
    int l = 0, r = n - 1;
    int inv = 0;
    for(int i = n - 1; i >= 0; i--) {
      if(f(s[r], inv) != t[i]) {
        if(f(s[l], inv) == t[i]) {
          v.push_back(0);
        }
        if(l < r) {
          l += 1;
        } else {
          l -= 1;
        }
        swap(l, r);
        v.push_back(i);
        inv ^= 1;
      } else {
        if(l < r) {
          r -= 1;
        } else {
          r += 1;
        }
      }
    }
    cout << v.size() << " " ;
    for(auto i : v) cout << i + 1 << " ";
    cout << endl;
  }
  return 0;
}
