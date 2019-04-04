#include "bits/stdc++.h"
using namespace std;
int a[200010], p[200010];
int pos[200010];
int n, m, q;

typedef pair <int, int> pii;

int dp[200010];
int fn[200010];
int last[200010];
vector <pair <int, int>> v[200010];

int opt[200010];

int t[200010 * 4];

void build(int c = 1, int b = 1, int e = m) {
	if(b == e) {
		t[c] = opt[b];
		return ;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	build(l, b, m);
	build(r, m + 1, e);
	t[c] = max(t[l], t[r]);
}
int query(int x, int y, int c = 1, int b = 1, int e = m) {
	if(x <= b && e <= y) {
		return t[c];
	}
	if(y < b || e < x) return 0;
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	return max(query(x, y, l, b, m), query(x, y, r, m + 1, e));
} 

int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		pos[p[i]] = i;
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
	}
	memset(last, 0, sizeof last);
	for(int i = 1; i <= m; i++) {
		if(a[i] == p[1]) {
			dp[i] = i;
		} else {
			int x = p[pos[a[i]] - 1];
			dp[i] = dp[last[x]];
		}
		last[a[i]] = i;
	}
	memset(last, 0, sizeof last);
	fn[0] = m + 1;
	for(int i = m; i >= 1; i--) {
		if(a[i] == p[n]) {
			fn[i] = i;
		} else {
			int x = p[pos[a[i]] + 1];
			fn[i] = fn[last[x]];
		}
		last[a[i]] = i;
	}
	for(int i = 1; i <= m; i++) {
		v[a[i]].emplace_back(fn[i], i);
	}
	for(int i = 1; i <= m; i++) {
		if(a[i] == p[n]) {
			opt[i] = dp[i];
			continue;
		}
		int x = p[pos[a[i]] + 1];
		int id = lower_bound(v[x].begin(), v[x].end(), pii(dp[i], -1)) - v[x].begin();
		if(id > 0) {
			int idx = v[x][id - 1].second;
			opt[i] = idx;
		}
	}
	build();
	vector <int> ans;
	while(q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		ans.push_back(query(l, r) >= l);
	}
	for(int i : ans) {
		printf("%d", i);
	}
	printf("\n");
	return 0;
}