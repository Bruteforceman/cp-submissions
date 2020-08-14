#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    int n;
    string s;
    cin >> n >> s;
    map <int, int> cnt;
    cnt[0] = 1;
    int sum = 0;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
      sum += s[i - 1] - '0';
      ans += cnt[sum - i];
      cnt[sum - i] += 1;
    }
    cout << ans << endl;
  }
  return 0;
}
