#include <bits/stdc++.h>
using namespace std;
int n, k;
int toBin(string s) {
  int pw = 1;
  int ans = 0;
  for(int i = 0; i < s.size(); i++) {
    ans += pw * (s[i] == '1');
    pw = pw * 2;
  }
  return ans;
}
int code[10];
int a[2005];
int mem[2006][2006];

int dp(int cur, int left) {
  if(left < 0) return false;
  if(cur == n) return (left == 0);
  int &ans = mem[cur][left];
  if(ans != -1) return ans;
  ans = 0;
  for(int i = 0; i < 10; i++) {
    if((a[cur] & code[i]) == a[cur]) {
      ans |= dp(cur + 1, left - __builtin_popcount(a[cur] ^ code[i]));
    }
  }
  return ans;
}
int main() {
  vector <string> arr ({"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"});
  for(int i = 0; i < 10; i++) {
    code[i] = toBin(arr[i]);
  }
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    string t;
    cin >> t;
    a[i] = toBin(t);
  }
  memset(mem, -1, sizeof mem);
  if(dp(0, k)) {
    int cur = 0;
    int left = k;
    while(cur < n) {
      for(int i = 9; i >= 0; i--) {
        if((a[cur] & code[i]) == a[cur]
            && dp(cur + 1, left - __builtin_popcount(a[cur] ^ code[i]))) {
          cout << i;
          left -= __builtin_popcount(a[cur] ^ code[i]);
          break;
        }
      }
      ++cur;
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;

}
