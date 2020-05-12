#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int n, m;
bool inside(int x, int y) {
  return (1 <= x && x <= n) && (1 <= y && y <= m);
}
char s[1005][1005];
bool good[1005][1005];
long long dist[1005][1005];
const long long inf = 2e18;

int main() {
  int q;
  scanf("%d %d %d", &n, &m, &q);
  for(int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  queue <pair <int, int>> Q;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      for(int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if(inside(x, y) && s[x][y] == s[i][j]) {
          good[i][j] = true;
        }
      }
      dist[i][j] = inf;
      if(good[i][j]) {
        dist[i][j] = 0;
        Q.push(make_pair(i, j));
      }
    }
  }
  while(!Q.empty()) {
    int i = Q.front().first;
    int j = Q.front().second;
    Q.pop();
    for(int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if(inside(x, y) && dist[x][y] > 1 + dist[i][j]) {
        dist[x][y] = 1 + dist[i][j];
        Q.push(make_pair(x, y));
      }
    }
  }
  for(int i = 1; i <= q; i++) {
    int x, y;
    long long t;
    scanf("%d %d %lld", &x, &y, &t);
    int val = s[x][y] - '0';
    if(dist[x][y] <= t) {
      val ^= (t - dist[x][y]) % 2;
    }
    printf("%d\n", val);
  }
}
