#include <bits/stdc++.h>
using namespace std;
const int bit = 61;
const int mod = 1e9 + 7;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector <long long> a (n);
    vector <int> cnt (bit);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      for(int j = 0; j < bit; j++) {
        if((a[i] >> j) & 1) {
          cnt[j] += 1;
        }
      }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      long long and_sum = 0, or_sum = 0;
      for(int x = 0; x < bit; x++) {
        long long pw = (1LL << x) % mod;
        if((a[i] >> x) & 1) {
          and_sum += cnt[x] * pw;
          or_sum += n * pw;
        } else {
          or_sum += cnt[x] * pw;
        }
        and_sum %= mod;
        or_sum %= mod;
      }
      ans += and_sum * or_sum;
      ans %= mod;
    }
    cout << ans << '\n';
  }
  return 0;
}
