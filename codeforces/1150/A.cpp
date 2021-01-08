#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector <int> a (n), b (m);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];
  int cnt = r / *min_element(a.begin(), a.end());
  int extra = r % (*min_element(a.begin(), a.end()));
  cout << max(r, cnt * (*max_element(b.begin(), b.end())) + extra) << endl;
  return 0;
}
