#include <bits/stdc++.h>
using namespace std;
const int maxn = 7e4 + 10;
bitset <maxn> dp, done;
pair <int, int> a[maxn];
int b[maxn], inside[maxn];
int first[maxn];

int main() {
  int n, s;
  cin >> n >> s;
  for(int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    b[i] = a[i].first;
  }
  sort(a + 1, a + n + 1);
  dp[0] = 1;
  done[0] = 1;
  for(int i = 1; i < n; i++) {
    dp |= dp << a[i].first;
    done = dp ^ done;
    for(int j = done._Find_first(); j < done.size(); j = done._Find_next(j)) {
      first[j] = i;
    }
    done = dp;
  }
  int cur = s - a[n].first;
  if(cur < 0 || !dp[cur]) {
    cout << -1 << endl;
    exit(0);
  }
  vector <int> take ({n});
  while(cur > 0) {
    take.push_back(first[cur]);
    cur -= a[first[cur]].first;
  }
  take.push_back(0);
  sort(take.begin(), take.end());
  for(int i = 1; i < take.size(); i++) {
    for(int j = take[i - 1] + 1; j < take[i]; j++) {
      inside[a[j + 1].second] = a[j].second;
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << b[i] - b[inside[i]] << ' ';
    if(inside[i]) cout << 1 << ' ' << inside[i] << endl;
    else cout << 0 << endl;
  }
  return 0;
}
