#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 2005;
int a[maxn], b[maxn];
int main() {
  ios_base :: sync_with_stdio (false); 
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) {
    int x; cin >> x; b[x] = i;
  }
  for(int i = 1; i <= n; i++) a[i] = b[a[i]];
  int ans = 0;
  for(int i = 1; i <= n; i++) ans += abs(a[i] - i);
  cout << ans / 2 << endl;
  vector <pair <int, int>> v;
  while(ans > 0) {
    int piv = n + 1, idx = n + 1;
    for(int i = 1; i <= n; i++) {
      if(a[i] < i) {
        if(piv > a[i]) {
          piv = a[i];
          idx = i;
        }
      }
    }
    for(int i = 1; i <= n; i++) {
      if(i == idx) continue;
      if(i < a[i] && piv <= i && i <= idx && idx <= a[i]) {
        v.emplace_back(idx, i);
        ans -= 2 * abs(idx - i);
        swap(a[idx], a[i]);
        break;
      }
    }
  }
  cout << v.size() << endl;
  for(int i = 0; i < v.size(); i++) cout << v[i].first << ' ' << v[i].second << endl;
  return 0;
}
