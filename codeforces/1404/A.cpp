#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 3e5 + 10;
int arr[maxn];
void solve() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  fill(arr, arr + k, -1);
  for(int i = 0; i < n; i++) {
    if(s[i] == '?') continue;
    int val = s[i] - '0';
    if(arr[i % k] == -1) {
      arr[i % k] = val;
    } else if (arr[i % k] != val) {
      cout << "NO" << endl;
      return ;
    }
  }
  int cnt[] = {0, 0};
  for(int i = 0; i < k; i++) {
    if(arr[i] == -1) continue;
    cnt[arr[i]] += 1;
  }
  if(cnt[0] <= (k / 2) && cnt[1] <= (k / 2)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios_base :: sync_with_stdio (false);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}
