#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3;
#define index indices
int a[maxn];
deque <int> Q;
int n, k;

int add(int id) {
  cout << "? " << id << endl;
  string s;
  cin >> s;
  return s == "Y" ? true : false;
}
void clear() {
  cout << "R" << endl;
  Q.clear();
}

vector <int> index[maxn];
int block[maxn];
bool del[maxn];

int main() {
  cin >> n >> k;
  int size = max(1, k / 2);
  int noBlock = n / size;
  for(int i = 1; i <= n; i++) {
    block[i] = (i - 1) / size + 1;
    index[block[i]].push_back(i);
  }
  for(int i = 1; i <= 2 * size && i <= n; i++) {
    del[i] = add(i);
  }
  clear();
  for(int i = 3; i <= noBlock; i++) {
    for(int j = 1; j < i; j += 2) {
      for(int k : index[j]) {
        if(!del[k]) {
          del[k] = add(k);
        }
      }
      for(int k : index[i]) {
        if(!del[k]) {
          del[k] = add(k);
        }
      }
      for(int k : index[j + 1]) {
        if(j + 1 < i && !del[k]) {
          del[k] = add(k);
        }
      }
      clear();
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += (del[i] == false);
  }
  cout << "! " << ans << endl;
  return 0;
}
