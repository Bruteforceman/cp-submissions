#include <bits/stdc++.h>
using namespace std;
int a[300100], p[300100];
vector <int> start[300010], fin[300010];
int out[300010];
int t[300010 * 4], prop[300010 * 4];
int n;
void pushdown(int c, int b, int e) {
	if(prop[c] == 0) return ;
	prop[c] = 0;
	int l = c << 1;
	int r = l + 1;
	int m = (b + e) >> 1;
	prop[l] ^= 1; prop[r] ^= 1;
	t[l] = (m - b + 1) - t[l];
	t[r] = (e - m) - t[r];
}
void update(int x, int y, int c = 1, int b = 0, int e = n-1) {
	if(x <= b && e <= y) {
		t[c] = (e - b + 1) - t[c];
		prop[c] ^= 1;
		return ;
	}
	if(y < b || e < x) return ;
	pushdown(c, b, e);
	int l = c << 1;
	int r = l + 1;
	int m = (b + e) >> 1;
	update(x, y, l, b, m);
	update(x, y, r, m + 1, e);
	t[c] = t[l] + t[r];
}
int query(int x, int y, int c = 1, int b = 0, int e = n -1) {
	if(x > y) return 0;
	if(x <= b && e <= y) {
		return t[c];
	}
	if(y < b || e < x) return 0;
	pushdown(c, b, e);
	int l = c << 1;
	int r = l + 1;
	int m = (b + e) >> 1;
	return query(x, y, l, b, m) + query(x, y, r, m + 1, e); 
}

int main() {
	int k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for(int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		int l = lower_bound(a, a + n, x) - a;
		int r = upper_bound(a, a + n, y) - a - 1;
		if(l >= r) continue;
		start[l].push_back(r);
		fin[r].push_back(l);
	}
	for(int i = n-1; i >= 0; i--) {
		out[i] += query(i + 1, n);
		for(auto r : start[i]) {
			update(i, r);
		}
		for(auto l : fin[i]) {
			update(l, i);
		}
	}	
	memset(t, 0, sizeof t);
	memset(prop, 0, sizeof prop);
	for(int i = 0; i < n; i++) {
		out[i] += i - query(0, i - 1);
		for(auto r : start[i]) {
			update(i, r);
		}
		for(auto l : fin[i]) {
			update(l, i);
		}
	}
	long long ans = (1LL * n * (n - 1) * (n - 2)) / 6;
	for(int i = 0; i < n; i++) {
		ans -= (1LL * out[i] * (out[i] - 1)) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}