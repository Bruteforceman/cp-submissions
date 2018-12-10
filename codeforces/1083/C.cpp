#include "bits/stdc++.h"
using namespace std;
vector <int> g[200010];
int dp[19][200010];
const int logn = 18;
int dep[200010];
int beg[200010], fin[200010];
int cur;
typedef pair <int, int> pii;

void dfs(int x, int par) {
	dp[0][x] = par;
	beg[x] = ++cur;
	for(auto i : g[x]) {
		if(i - par) {
			dep[i] = 1 + dep[x];
			dfs(i, x);
		}
	}
	fin[x] = ++cur;
}
int lift(int x, int lv) {
	for(int i = logn; i >= 0; i--) {
		if(dep[x] - (1 << i) >= lv) {
			x = dp[i][x];
		}
	}
	return x;
}
int lca(int p, int q) {
	if(dep[p] > dep[q]) swap(p, q);
	for(int i = logn; i >= 0; i--) {
		if(dep[q] - (1 << i) >= dep[p]) {
			q = dp[i][q];
		}
	}
	if(p == q) return p;
	for(int i = logn; i >= 0; i--) {
		if(dp[i][p] != dp[i][q]) {
			p = dp[i][p];
			q = dp[i][q];
		}
	}
	return dp[0][p];
}
int on_path(int x, int y, int p) {
	int anc = lca(x, y);
	if(dep[anc] > dep[p]) return false;
	return (lift(x, dep[p]) == p) || (lift(y, dep[p]) == p);
}
pii path(int a, int b, int c, int d) {
	if(a == -1 || b == -1 || c == -1 || d == -1) return pii(-1, -1);
	int x = min(pii(fin[a], a), min(pii(fin[b], b), min(pii(fin[c], c), pii(fin[d], d)))).second;
	int y = max(pii(beg[a], a), max(pii(beg[b], b), max(pii(beg[c], c), pii(beg[d], d)))).second;
	if(x == y) {
		int other = min(pii(dep[a], a), min(pii(dep[b], b), min(pii(dep[c], c), pii(dep[d], d)))).second;
		return pii(other, x);
	}

	if(on_path(x, y, a) && on_path(x, y, b) && on_path(x, y, c) && on_path(x, y, d)) {
		return pii(x, y);
	} else {
		return pii(-1, -1);
	}
}

pii t[200010 * 4];
int per[200010];
int a[200010];
int n;

void update(int x, int val, int c = 1, int b = 0, int e = n-1) {
	if(b == e) {
		t[c] = pii(val, val);
		return ;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	if(x <= m) {
		update(x, val, l, b, m);
	} else {
		update(x, val, r, m+1, e);
	}
	t[c] = path(t[l].first, t[l].second, t[r].first, t[r].second);
}
int query(pii cur, int c = 1, int b = 0, int e = n-1) {
	if(b == e) {
		return path(cur.first, cur.second, t[c].first, t[c].second).first == -1 ? (b-1) : b;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	pii P = path(cur.first, cur.second, t[l].first, t[l].second);
	if(P.first == -1) {
		return query(cur, l, b, m);
	} else {
		return query(P, r, m+1, e);
	}
}
void build(int c = 1, int b = 0, int e = n-1) {
	if(b == e) {
		t[c] = pii(per[b], per[b]);
		return ;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	build(l, b, m);
	build(r, m+1, e);
	t[c] = path(t[l].first, t[l].second, t[r].first, t[r].second);
	// cout << b << " " << e << " " << t[c].first << ' ' << t[c].second << endl;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int p;
		scanf("%d", &p);
		per[p] = i;
		a[i] = p;
	}
	for(int i = 2; i <= n; i++) {
		int d;
		scanf("%d", &d);
		g[d].emplace_back(i);
	}
	dfs(1, 0);
	for(int i = 1; i <= logn; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	build();

	int q;
	scanf("%d", &q);
	while(q--) {
		int x, y;
		int c;
		scanf("%d", &c);
		if(c == 2) {
			printf("%d\n", query(pii(per[0], per[0])) + 1);
			continue;
		}
		scanf("%d %d", &x, &y);
		swap(per[a[x]], per[a[y]]);
		update(a[x], per[a[x]]);
		update(a[y], per[a[y]]);
		swap(a[x], a[y]);
	}
	return 0;
}