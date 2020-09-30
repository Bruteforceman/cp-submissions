#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector <int> a (n), b (n), c (n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    vector <int> ans (n, -1);
    for(int i = 0; i < n; i++) {
      for(int j : {a[i], b[i], c[i]}) {
        if(ans[(n + i - 1) % n] != j && ans[(i + 1) % n] != j) {
          ans[i] = j;  
          break;
        }
      }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
