#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> moves;
void change(vector <int> &v, vector <int> d) {
  int cur = 0;
  vector <int> u;
  vector <int> outp;
  for(int i : d) {
    for(int j = cur + i - 1; j >= cur; j--) {
      u.push_back(v[j]);
    }
    cur += i;
    if(i) outp.push_back(i);
  }
  reverse(u.begin(), u.end());
  v = u;
  if(outp.size() > 1) {
    moves.push_back(outp);
  }
}
int main() {
  int n;
  cin >> n;
  vector <int> v (n);
  for(int i = 0; i < n; i++) cin >> v[i];
  if(n == 1) {
    cout << 0 << endl;
    exit(0);
  }
  int l = (n / 2) + 1, r = (n / 2) + 1;
  int pos = find(v.begin(), v.end(), l) - v.begin();
  change(v, {pos, n - pos});

  bool isLeft = true;
  while(!is_sorted(v.begin(), v.end())) {
    if(isLeft) {
      int cur = l - 1;
      int pos = find(v.begin(), v.end(), cur) - v.begin();
      int p = r - l + 1;
      int q = pos + 1 - p;
      int f = n - p - q;
      change(v, {p, q, f});
      l -= 1;
    } else {
      int cur = r + 1;
      int pos = find(v.begin(), v.end(), cur) - v.begin();
      int p = r - l + 1;
      int q = n - pos - p;
      int f = n - p - q;
      change(v, {f, q, p});
      r += 1;
    }
    isLeft ^= 1;
  }
  cout << moves.size() << endl;
  for(auto i : moves) {
    cout << i.size();
    for(auto j : i) cout << " " << j;
    cout << endl;
  }
}
