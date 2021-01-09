#include <bits/stdc++.h>
using namespace std;

bool check(int a) {
  set <int> s;
  int cnt = 0;
  while(a) {
    s.insert(a % 10);
    ++cnt;
    a /= 10;
  }
  return s.size() == cnt;
}

int main() {  
  int l, r;
  cin >> l >> r;
  for(int i = l; i <= r; i++) {
    if(check(i)) {
      cout << i << endl;
      exit(0);
    }
  }
  cout << -1 << endl;
  return 0;
}
