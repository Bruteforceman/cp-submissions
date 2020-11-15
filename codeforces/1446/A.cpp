#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve() {
  int n;
  long long W;
  cin >> n >> W;
  vector <long long> a (n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long low = (W + 1) / 2;
  long long sum = 0;
  vector <int> idx;
  for(int i = 0; i < n; i++) {
    if(a[i] > W) continue;
    if(low <= a[i]) {
      cout << 1 << endl;
      cout << i + 1 << endl;
      return ;
    }
    if(sum + a[i] <= W) { 
      sum += a[i];
      idx.push_back(i + 1);
    }
  }
  if(low <= sum && sum <= W) {
    cout << idx.size() << endl;
    for(auto i : idx) cout << i << " ";
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}
int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}
