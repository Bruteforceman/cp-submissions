#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
string s;
long long cnt[26];
int n, k;

int main() {
  cin >> s >> k;
  n = s.size();
  vector <int> can;
  if(1LL * n * (n + 1) / 2 < k) {
    cout << "No such line." << endl;
    exit(0);
  }
  k += n - 1;
  for(int i = 0; i < n; i++) can.push_back(i);
  string t = "";
  while(true) {
    memset(cnt, 0, sizeof cnt);
    for(int i : can) {
      if(i < n) cnt[s[i] - 'a'] += n - i;
    }
    if(can.size() > k) {
      break;
    } else k -= can.size();
    int cur = 0;
    while(cur < 26) {
      if(cnt[cur] > k) break;
      k -= cnt[cur];
      cur = cur + 1;
    }
    t += char(cur + 'a');
    vector <int> aux;
    for(int i : can) {
      if(i < n && s[i] == t.back()) {
        aux.push_back(i + 1);
      }
    }
    can.swap(aux);
  }
  cout << t << endl;
  return 0;
}
