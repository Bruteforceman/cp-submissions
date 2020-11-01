#include <bits/stdc++.h>
using namespace std;

long long maxDiv(long long x, long long y) {
  long long ret = 1;
  while(x % y == 0) {
    x /= y;
    ret *= y;
  }
  return ret;
}

void solve() {
  long long p, q;
  cin >> p >> q;
  if(p % q != 0) {
    cout << p << endl;
    return ;
  }
  vector <long long> factors;
  long long temp = q;
  for(long long i = 2; i * i <= q; i++) {
    if(q % i == 0) {
      factors.push_back(i);
      while(q % i == 0) q /= i;
    }
  }
  if(q > 1) factors.push_back(q);
  long long opt = p;
  q = temp;
  for(auto i : factors) {
    opt = min(opt, (maxDiv(p, i) / maxDiv(q, i)) * i);
  } 
  cout << p / opt << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
