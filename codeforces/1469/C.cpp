#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector <int> a (n);
    vector <int> ord (n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      ord[i] = i;
    }
    sort(ord.begin(), ord.end(), [&] (int i, int j) { return a[i] > a[j]; } );
    vector <int> h (n, 0);
    for(int x = 0; x < n; x++) {
      int i = ord[x];
      int opt = a[i];
      if(i > 0) opt = max(opt, h[i - 1] - k + 1);
      if(i < n - 1) opt = max(opt, h[i + 1] - k + 1);
      h[i] = opt;
    }
    bool bad = (h[0] != a[0]) || (h[n - 1] != a[n - 1]);
    for(int i = 0; i < n; i++) bad |= (h[i] - a[i]) >= k;
    if(bad) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
  return 0;
}
