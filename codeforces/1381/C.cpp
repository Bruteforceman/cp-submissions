#include <bits/stdc++.h>
using namespace std;
const int maxn  = 1e5 + 10;
int a[maxn], b[maxn];
int n;
vector <int> v[maxn];
int ord[maxn];

void solve(vector <int> id) {
  for(int i = 1; i <= n + 1; i++) v[i].clear();
  for(int i : id) {
    v[b[i]].push_back(i);
  }
  for(int i = 1; i <= n + 1; i++) ord[i] = i;
  sort(ord + 1, ord + n + 1 + 1, [&] (int i, int j) {
      return v[i].size() < v[j].size(); } );
  
  vector <int> extra;
  for(int i = 1; i < n + 1; i++) {
    int x = ord[i];
    for(int j : v[x]) {
      a[j] = ord[i + 1];
    }
    if(i < n) {
      int dif = v[ord[i + 1]].size() - v[ord[i]].size();
      for(int j = 1; j <= dif; j++) {
        extra.push_back(ord[i + 1]);
      }
    }
  }
  int last = ord[n + 1];
  for(int i = 1; i <= n + 1; i++) {
    int x = ord[i];
    for(int j : v[x]) {
      if(extra.size() >= v[last].size()) break;    
      extra.push_back(a[j]);
      a[j] = last;
    }
  }
  for(int j = 0; j < v[last].size(); j++) {
    int x = v[last][j];
    a[x] = extra[j];
  }
}

void test() {
  int x, y;
  scanf("%d %d %d", &n, &x, &y);
  for(int i = 1; i <= n + 1; i++) {
    v[i].clear();
    a[i] = 0;
    ord[i] = i;
  }
  for(int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    v[b[i]].push_back(i);
  }
  vector <int> aux;
  int sz = -1;
  int pt = 0, sum = 0;
  for(int i = 1; i <= n + 1; i++) aux.push_back(v[i].size());
  sort(aux.begin(), aux.end());
  for(int j = 1; j <= n - x; j++) {
    while(pt < aux.size() && aux[pt] <= j / 2) {
      sum += aux[pt];
      ++pt;
    }
    int total = sum + (aux.size() - pt) * (j / 2);
    if(total >= j && j >= y - x) {
      sz = j;
      break;
    }
  }
  if(y > x && sz == -1) {
    puts("NO");
    return ;
  }

  int var = 0;
  vector <int> id;
  for(int i = 1; i <= n + 1; i++) {
    if(v[i].size() == 0) var = i;
    int ans = 0;
    for(int j = 0; j < v[i].size() && j < sz / 2; j++) {
      if(id.size() < sz) {
        id.push_back(v[i][j]);
      }
    }
  }
  solve(id);
  y -= x;
  for(int i = 1; i <= n; i++) {
    if(a[i] == 0) continue;
    if(y > 0) {
      y -= 1;
    } else {
      a[i] = var;
    }
  }
  for(int i = 1; i <= n; i++) {
    if(a[i] != 0) continue;
    if(x > 0) {
      a[i] = b[i];
      x -= 1;
    } else {
      a[i] = var;
    }
  }
  printf("YES\n");
  for(int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    test();
  }
  return 0;
}
