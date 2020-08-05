#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int amin = *min_element(a.begin(), a.end());
    int bmin = *min_element(b.begin(), b.end());
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      int diff = min(a[i] - amin, b[i] - bmin);
      a[i] -= diff; b[i] -= diff;
      ans += diff;
      ans += (a[i] - amin);
      ans += (b[i] - bmin);
    }
    cout << ans << endl;
  }
  return 0;
}
