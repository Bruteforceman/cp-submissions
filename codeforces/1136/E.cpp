#include "bits/stdc++.h"
using namespace std;
int n;

struct Rep {
	int prop[100010 * 4];
	void pushdown(int c) {
		if(prop[c] == 0) return ;
		int l = c << 1;
		int r = l + 1;
		prop[l] = prop[r] = prop[c];
		prop[c] = 0;
	}
	void update(int x, int y, int val, int c, int b, int e) {
		if(x <= b && e <= y) {
			prop[c] = val;
			return ;
		}
		if(y < b || e < x) return ;
		pushdown(c);
		int l = c << 1;
		int r = l + 1;
		int m = (b + e) >> 1;
		update(x, y, val, l, b, m);
		update(x, y, val, r, m+1, e);
	}
	int query(int x, int c, int b, int e) {
		if(b == e) {
			return prop[c];
		}
		pushdown(c);
		int m = (b + e) >> 1;
		int l = c << 1;
		int r = l + 1;
		if(x <= m) return query(x, l, b, m);
		else return query(x, r, m + 1, e);
	}
	void update(int x, int y, int val) {
		if(x > y) return ;
		update(x, y, val, 1, 1, n);
	}
	int query(int x) {
		return query(x, 1, 1, n);
	}
} A, B;
struct Tree {
	long long t[100010 * 4];
	long long prop[100010 * 4];
	void pushdown(int c, int b, int e) {
		int l = c << 1;
		int r = l + 1;
		int m = (b + e) >> 1;
		t[l] += prop[c] * (m - b + 1);
		t[r] += prop[c] * (e - m);
		prop[l] += prop[c];
		prop[r] += prop[c];
		prop[c] = 0;
	}
	void update(int x, int y, long long val, int c, int b, int e) {
		if(x <= b && e <= y) {
			t[c] += val * (e - b + 1);
			prop[c] += val;
			return ; 
		}
		if(y < b || e < x) return ;
		pushdown(c, b, e);
		int l = c << 1;
		int r = l + 1;
		int m = (b + e) >> 1;
		update(x, y, val, l, b, m);
		update(x, y, val, r, m + 1, e);
		t[c] = t[l] + t[r];
	}
	long long query(int x, int y, int c, int b, int e) {
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
	void update(int x, int y, int val) {
		if(x > y) return ;
		update(x, y, val, 1, 1, n);
	}
	long long query(int x, int y) {
		if(x > y) return 0;
		return query(x, y, 1, 1, n);
	}
} Q;

long long a[100010];
long long k[100010];

void shift(int x, long long val) {
	int head = A.query(x);
	int tail = B.query(x);
	B.update(head, x - 1, x - 1);
	Q.update(x, tail, val);
	while(tail < n) {
		long long p = Q.query(tail, tail);
		long long q = Q.query(tail + 1, tail + 1);
		if(p + k[tail] >= q) {
			int nxt = B.query(tail + 1);
			Q.update(tail + 1, nxt, p + k[tail] - q);
			tail = nxt;
		} else {
			break;
		}
	}
	A.update(x, tail, x);
	B.update(x, tail, tail);
}
long long answer(int x, int y) {
	return Q.query(x, y);
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		Q.update(i, i, a[i]);
		A.update(i, i, i);
		B.update(i, i, i);
	}
	for(int i = 1; i < n; i++) {
		scanf("%lld", &k[i]);
	}
	int qr;
	scanf("%d", &qr);
	for(int i = 1; i <= qr; i++) {
		char c;
		int x, y;
		scanf(" %c %d %d", &c, &x, &y);
		if(c == '+') {
			shift(x, y);
		} else {
			printf("%lld\n", answer(x, y));
		}
	}
	return 0;
}