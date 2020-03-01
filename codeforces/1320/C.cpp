#include "bits/stdc++.h"
using namespace std;
using pii = pair <int, int>;
const int maxn = 1000005;
long long t[maxn * 4];
long long prop[maxn * 4];
long long optA[maxn], optB[maxn];
vector <pii> v[maxn];
const long long inf = 1e16;

void pushdown(int c) {
	int l = c << 1;
	int r = l + 1;
	prop[l] += prop[c];
	prop[r] += prop[c];
	t[l] += prop[c];
	t[r] += prop[c];
	prop[c] = 0;
}
void build(int c = 1, int b = 1, int e = maxn - 1) {
	if(b == e) {
		t[c] = -optB[b];
		prop[c] = 0;
		return ; 
	}
	int l = c << 1;
	int r = l + 1;
	int m = (b + e) >> 1;
	build(l, b, m);
	build(r, m + 1, e);
	t[c] = max(t[l], t[r]);
}
void update(int x, int y, int val, int c = 1, int b = 1, int e = maxn - 1) {
	if(x <= b && e <= y) {
		t[c] += val;
		prop[c] += val;
		return ;
	}
	if(y < b || e < x) return ;
	pushdown(c);
	int l = c << 1;
	int r = l + 1;
	int m = (b + e) >> 1;
	update(x, y, val, l, b, m);
	update(x, y, val, r, m + 1, e);
	t[c] = max(t[l], t[r]);
}

int main(int argc, char const *argv[])
{
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	fill(optA, optA + maxn, inf);
	fill(optB, optB + maxn, inf);
	for(int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		optA[x] = min(optA[x], 1LL * y);
	}
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		optB[x] = min(optB[x], 1LL * y);
	}
	for(int i = 1; i <= p; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		v[x].emplace_back(y, z);
	}
	build();
	long long ans = -inf;
	for(int i = 1; i < maxn; i++) {
		ans = max(ans, t[1] - optA[i]);
		for(auto j : v[i]) {
			update(j.first + 1, maxn - 1, j.second);
		}
	}
	printf("%lld\n", ans);
	return 0;
}