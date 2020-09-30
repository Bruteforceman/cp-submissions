#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, l;
  scanf("%d %d", &n, &l);
  vector <int> a (n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  a.push_back(0);
  a.push_back(l);
  sort(a.begin(), a.end());
  vector <double> reachA (n + 2), reachB (n + 2);
  reachA[0] = 0;
  for(int i = 1; i < a.size(); i++) {
    reachA[i] = reachA[i - 1] + double(a[i] - a[i - 1]) / i;
  }
  reachB[a.size() - 1] = 0;
  for(int i = a.size() - 2; i >= 0; i--) {
    reachB[i] = reachB[i + 1] + double(a[i + 1] - a[i]) / (a.size() - i - 1);
  }
  for(int i = 1; i < a.size(); i++) {
    if(reachA[i] >= reachB[i]) {
      double left = a[i - 1], right = a[i];
      double v = i + (a.size() - i);
      double dif = fabs(reachA[i - 1] - reachB[i]);
      if(reachA[i - 1] > reachB[i]) {
        right -= dif * (a.size() - i);
      } else {
        left += dif * i;
      }
      printf("%.9lf\n", max(reachA[i - 1], reachB[i]) + (right - left) / v);
      return ;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}
