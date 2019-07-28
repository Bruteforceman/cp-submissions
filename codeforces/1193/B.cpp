#include "bits/stdc++.h"
using namespace std;
typedef pair <int, long long> pii;

vector <int> g[100010];
int d[100010], w[100010];
int n, m, k;
int l[100010], r[100010];
int ord[100010];
vector <pii> v[100010];
int sub[100010];
int cur;

long long sum[100010 * 4];
long long mx[100010 * 4];
long long mn[100010 * 4];
long long val[100010 * 4];

void addNode(int c, long long value) {
	if(val[c] == -1) {
		sum[c] += value;
	} else {
		val[c] += value;
	}
	mx[c] += value;
	mn[c] += value;
}
void assignNode(int c, long long value) {
	val[c] = value;
	mx[c] = value;
	mn[c] = value;
	sum[c] = 0;
}
void pushdown(int c) {
	int l = c << 1;
	int r = l + 1;
	if(val[c] == -1) {
		addNode(l, sum[c]);
		addNode(r, sum[c]);
		sum[c] = 0;
	} else {
		assignNode(l, val[c]);
		assignNode(r, val[c]);
		val[c] = -1;
	}
}
void add(int x, int y, long long value, int c = 1, int b = 1, int e = k) {
	if(x > y) return ;
	if(x <= b && e <= y) {
		addNode(c, value);
		return ;
	}
	if(y < b || e < x) return ;
	pushdown(c);
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	add(x, y, value, l, b, m);
	add(x, y, value, r, m + 1, e);
	mx[c] = max(mx[l], mx[r]);
	mn[c] = min(mn[l], mn[r]);
}
void adjust(int x, int y, long long value, int c = 1, int b = 1, int e = k) {
	if(x <= b && e <= y && mx[c] <= value) {
		assignNode(c, value);
		return ;
	} 
	if(y < b || e < x || mn[c] >= value) return ;
	pushdown(c);
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	adjust(x, y, value, l, b, m);
	adjust(x, y, value, r, m + 1, e);	
	mx[c] = max(mx[l], mx[r]);
	mn[c] = min(mn[l], mn[r]);
}
long long get(int x, int c = 1, int b = 1, int e = k) {
	if(b == e) {
		return mn[c];
	}
	pushdown(c);
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	if(x <= m) return get(x, l, b, m);
	else return get(x, r, m + 1, e);
}
// long long get(int x) {
// 	return t[x];
// }
// void add(int x, int y, long long val) {
// 	for(int i = x; i <= y; i++) {
// 		t[i] += val;
// 	}
// }
// void adjust(int x, long long val) {
// 	for(int i = x; i <= k; i++) {
// 		t[i] = max(t[i], val);
// 	}
// }

// void init() {
// 	for(int i = 1; i <= k; i++) {
// 		t[i] = 0;
// 	}
// }
void subtree(int x) {
	sub[x] = 1;
	ord[++cur] = x;
	l[x] = cur;
	for(auto i : g[x]) {
		subtree(i);
		sub[x] += sub[i];
	}
	r[x] = cur;
}

void dfs(int x, int keep) {
	int big = -1;
	for(auto i : g[x]) {
		if(big == -1 || sub[big] < sub[i]) {
			big = i;
		}
	}
	for(auto i : g[x]) {
		if(i != big) {
			dfs(i, 0);
		}
	}
	if(big != -1) {
		dfs(big, 1);
	}
	for(auto i : g[x]) {
		if(i != big) {
			for(unsigned j = 0; j < v[i].size() - 1; j++) {
				add(v[i][j].first, v[i][j + 1].first - 1, v[i][j].second);
			}
			v[i].clear();
		}
	}
	if(d[x] > 0) {
		add(d[x], d[x], w[x]);
		adjust(d[x] + 1, k, get(d[x]));
	}
	if(!keep) {
		set <int> s;
		for(int i = l[x]; i <= r[x]; i++) {
			if(d[ord[i]] > 0) {
				s.insert(d[ord[i]]);
			}
		}
		for(auto i : s) {
			v[x].push_back(pii(i, get(i)));
		}
		v[x].push_back(pii(k + 1, 0));
		for(unsigned i = 0; i < v[x].size() - 1; i++) {
			add(v[x][i].first, v[x][i + 1].first - 1, -v[x][i].second);
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 2; i <= n; i++) {
		int par;
		scanf("%d", &par);
		g[par].push_back(i);	
	}
	for(int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		d[x] = y;
		w[x] = z;	
	}
	subtree(1);
	dfs(1, 1);
	printf("%lld\n", get(k));
	return 0;
}