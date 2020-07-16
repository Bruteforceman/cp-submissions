#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;

int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  map <pair <int, int>, vector <double>> cont;
  for(int i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    int d = __gcd(abs(x), abs(y));
    if(d == 0) continue;
    double dist = sqrt(x * x + y * y);
    cont[make_pair(x / d, y / d)].push_back(dist);
  }
  int idx = 0;
  vector <pair <double, int>> v;
  vector <vector <double>> lines;
  for(auto i : cont) {
    vector <double> u = i.second;
    sort(u.begin(), u.end(), greater <double> ());
    for(int j = 0; j < u.size(); j++) {
      v.emplace_back(u[j] * (k - 1 - 2 * j), idx);
    }
    u.push_back(0);
    reverse(u.begin(), u.end());
    lines.push_back(u);
    ++idx;
  }
  vector <int> cnt (idx);
  sort(v.begin(), v.end(), greater <pair <double, int>> ());
  double ans = 0;
  for(int i = 0; i < k; i++) {
    if(v[i].first >= 0) {
      ans += v[i].first;
      cnt[v[i].second] += 1;
    } else {
      int need = k - i;
      int id = v[i].second;
      for(int j = need - 1; j >= 0; j--) {
        ans += (k - 1 - 2 * cnt[id]) * lines[id][j];
        cnt[id] += 1;
      }
      break;
    }
  }
  cout << setprecision(10) << fixed << ans << endl;
  return 0;
}
