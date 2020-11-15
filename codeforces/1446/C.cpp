#include <bits/stdc++.h>
using namespace std;
const int bit = 30;
const int maxn = 2e5 + 10;
int a[maxn];
struct node {
  node *a[2];
  node () {
    a[0] = a[1] = NULL;
  }
} *root;
void insert(int val) {
  node* cur = root;
  for(int i = bit; i >= 0; i--) {
    int bit = (val >> i) & 1;
    if(cur -> a[bit] == NULL) {
      cur -> a[bit] = new node();
    }
    cur = cur -> a[bit];
  }
}
int query(int val) {
  node *cur = root;
  int cnt = 1;
  for(int i = bit; i >= 0; i--) {
    int bit = (val >> i) & 1;
    if(cur -> a[bit ^ 1]) ++cnt;
    cur = cur -> a[bit];
  }
  return cnt;
}
int main() {
  int n;
  scanf("%d", &n);
  root = new node();
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    insert(a[i]);
  }
  int ret = 0;
  for(int i = 0; i < n; i++) ret = max(ret, query(a[i]));
  printf("%d\n", n - ret);
  return 0;
}
