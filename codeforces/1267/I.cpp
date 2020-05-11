#include <bits/stdc++.h>
using namespace std;
char ask(int i, int j) {
  cout << "? " << i << " " << j << endl;
  char ans;
  cin >> ans;
  return ans;
}
void bubble_sort(vector <int> &v) {
  for(int i = 0; i < v.size(); i++) {
    for(int j = 1; j < v.size(); j++) {
      if(ask(v[j - 1], v[j]) == '>') swap(v[j - 1], v[j]);
    }
  }
}
void solve() {
  int n;
  cin >> n; 
  vector <int> a, b;
  for(int i = 1; i < n; i++) {
    a.push_back(i);
  }
  b.push_back(n); 
  bubble_sort(a); bubble_sort(b);
  for(int i = n + 1; i <= 2 * n; i++) {
    if(b.size() == 1) {
      b.push_back(i);
      for(int j = b.size() - 1; j > 0; j--) {
        if(ask(b[j - 1], b[j]) == '>') {
          swap(b[j - 1], b[j]);
        }
      }
    }
    else {
      a.push_back(i);
      for(int j = a.size() - 1; j > 0; j--) {
        if(ask(a[j - 1], a[j]) == '>') {
          swap(a[j - 1], a[j]);
        }
      }
    }
    if(ask(a[0], b[0]) == '<') {
      a.erase(a.begin());
    } else {
      b.erase(b.begin());
    }
  }
  cout << "! " << endl;
} 
int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
