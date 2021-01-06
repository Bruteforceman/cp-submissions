#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];

int main() {
  int n;
  cin >> n;
  stack <int> st;
  memset(a, -1, sizeof a);
  for(int i = 1; i <= 2 * n; i++) {
    char c;
    int x;
    cin >> c;
    if(c == '+') {
      st.push(i);
    } else {
      cin >> x;
      if(st.empty()) {
        cout << "NO" << endl;
        exit(0);
      }
      a[st.top()] = x;
      st.pop();
      b[i] = x;
    }
  }
  set <int> s;
  for(int i = 1; i <= 2 * n; i++) {
    if(a[i] != -1) {
      s.insert(a[i]);
    } else {
      int x = *s.begin();
      s.erase(x);
      if(b[i] != x) {
        cout << "NO" << endl;
        exit(0);
      }
    }
  }
  cout << "YES" << endl;
  for(int i = 1; i <= 2 * n; i++) {
    if(a[i] != -1) cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
