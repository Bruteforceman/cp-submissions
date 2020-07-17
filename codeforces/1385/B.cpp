#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    set <int> s;
    vector <int> p;
    for(int i = 1; i <= n + n; i++) {
      int x;
      cin >> x;
      if(s.count(x) == 0) p.push_back(x);
      s.insert(x);
    }
    for(int i : p) cout << i << ' ';
    cout << endl;
  }
}
