#include "bits/stdc++.h"
using namespace std;
int n;
int a[400010];
int t[400010 * 4];

int curL, curR;

const int inf = 1e9;

void upd(int x, int val, int c = 1, int b = 1, int e = 2*n) {
	if(b == e) {
		t[c] = val;
		return ;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	if(x <= m) upd(x, val, l, b, m);
	else upd(x, val, r, m+1, e);
	t[c] = min(t[l], t[r]);
}
int rmq(int x, int y, int c = 1, int b = 1, int e = 2*n) {
	if(x <= b && e <= y) return t[c];
	if(y < b || e < x) return inf;
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	return min(rmq(x, y, l, b, m), rmq(x, y, r, m + 1, e));
}
int bsPref(int x, int y, int val, int c = 1, int b = 1, int e = 2*n) {
	if(x <= b && e <= y && t[c] >= val) {
		return y + 1;
	}
	if(y < b || e < x) return y + 1;
	if(b == e) {
		return b;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	int p = bsPref(x, y, val, l, b, m);
	if(p <= y) return p;
	else return bsPref(x, y, val, r, m + 1, e); 
}
int bsSuf(int x, int y, int val, int c = 1, int b = 1, int e = 2*n) {
	if(x <= b && e <= y && t[c] >= val) {
		return x - 1;
	}
	if(y < b || e < x) return x - 1;
	if(b == e) {
		return b;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	int s = bsSuf(x, y, val, r, m + 1, e);
	if(x <= s) return s;
	else return bsSuf(x, y, val, l, b, m);
}

int dep[400010 * 4];
int prop[400010 * 4];

void pushdown(int c) {
	int l = c << 1;
	int r = l + 1;
	dep[l] += prop[c];
	dep[r] += prop[c];
	prop[l] += prop[c];
	prop[r] += prop[c];
	prop[c] = 0;
}
void add(int x, int y, int val, int c = 1, int b = 1, int e = 2*n) {
	if(x <= b && e <= y) {
		dep[c] += val;
		prop[c] += val;
		return ;
	}
	if(y < b || e < x) return ;
	pushdown(c);
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	add(x, y, val, l, b, m);
	add(x, y, val, r, m + 1, e);
	dep[c] = max(dep[l], dep[r]);
}
int ask(int x, int y, int c = 1, int b = 1, int e = 2*n) {
	if(x <= b && e <= y) {
		return dep[c];
	}
	if(y < b || e < x) return -inf;
	pushdown(c);
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	return max(ask(x, y, l, b, m), ask(x, y, r, m + 1, e));
}

void addLast(int val) {
	a[++curR] = val;
	upd(curR, val);
	int prev = bsSuf(curL, curR, val);
	int var = 0;
	if(curL <= prev) {
		var = ask(prev, prev);
	}
	add(prev + 1, curR, 1);
	add(curR, curR, var);
} 

void delFirst() {
	int nxt = bsPref(curL, curR, a[curL]) - 1;
	add(curL, nxt, -1);
	++curL;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	curL = 1;
	curR = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		addLast(a[i]);
	}
	int ans = ask(curL, curR);
	int opt = 0;
	for(int i = 1; i < n; i++) {
		delFirst();
		addLast(a[i]);
		int p = ask(curL, curR);
		ans = min(ans, p);
		if(ans == p) opt = i;	
	}
	printf("%d %d\n", ans, opt);
	return 0;
}