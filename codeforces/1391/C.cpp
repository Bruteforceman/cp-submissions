#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  long long factorial = 1;
  long long power = 1;
  for(int i = 1; i <= n; i++) {
    factorial = (factorial * i) % mod;
  }
  for(int i = 1; i < n; i++) {
    power = (power * 2) % mod;
  }
  cout << (factorial - power + mod) % mod << endl;
}
