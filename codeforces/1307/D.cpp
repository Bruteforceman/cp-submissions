#include "bits/stdc++.h"
using namespace std;
const int maxn = 200010;
vector <int> g[maxn];
bool mark[maxn];
int n, m, k;
int d[2][maxn];

void bfs(int src, int c) {
	d[c][src] = 0;
	queue <int> Q;
	Q.push(src);
	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for(auto i : g[x]) {
			if(d[c][i] == -1) {
				d[c][i] = d[c][x] + 1;
				Q.push(i);
			}
		}
	}
}

int t[maxn * 4];
void update(int x, int val, int c = 1, int b = 0, int e = n) {
	if(b == e) {
		t[c] = max(t[c], val);
		return ;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	if(x <= m) update(x, val, l, b, m);
	else update(x, val, r, m + 1, e);
	t[c] = max(t[l], t[r]);
}
int query(int x, int y, int c = 1, int b = 0, int e = n) {
	if(x <= b && e <= y) {
		return t[c];
	}
	if(y < b || e < x) return -n;
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	return max(query(x, y, l, b, m), query(x, y, r, m + 1, e));
}

bool good(int p) {
	p -= 1;
	fill(t, t + (4 * n + 1), -n);
	for(int i = 1; i <= n; i++) {
		if(mark[i]) {
			if(query(max(0, p - d[0][i]), n) >= max(0, p - d[1][i])) {
				return true;
			}
			update(d[1][i], d[0][i]);
		}
	}
	return false;
}

int search(int b, int e) {
	if(b == e) return b;
	int m = (b + e + 1) >> 1;
	if(good(m)) return search(m, e);
	else return search(b, m - 1);
}

void solve() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= k; i++) {
		int x;
		scanf("%d", &x);
		mark[x] = 1;
	}
	for(int i = 1; i <= m; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		g[p].push_back(q);
		g[q].push_back(p);
	}
	memset(d, -1, sizeof d);
	bfs(1, 0);
	bfs(n, 1);
	printf("%d\n", search(1, d[0][n]));
}
int main(int argc, char const *argv[])
{
	solve();
 	return 0; 
}