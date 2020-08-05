#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector <int> a (n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    bool bad = false;
    for(int i = 1; i < n; i++) {
      if(a[i] - a[i - 1] > 1) bad = true;
    }
    if(bad) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
  return 0;
}

