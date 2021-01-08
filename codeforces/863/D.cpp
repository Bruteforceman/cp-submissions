#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
int t[maxn], l[maxn], r[maxn];

int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);

  int n, q, m;
  cin >> n >> q >> m;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= q; i++) {
    cin >> t[i] >> l[i] >> r[i];
  }
  for(int i = 1; i <= m; i++) {
    int x; 
    cin >> x;
    for(int j = q; j >= 1; j--) {
      if(x < l[j] || r[j] < x) continue;
      if(t[j] == 2) {
        x = r[j] - x + l[j]; 
      } else {
        if(x == l[j]) x = r[j];
        else x -= 1;
      }
    }
    cout << a[x] << " "; 
  }
  cout << endl;
  return 0;
}
