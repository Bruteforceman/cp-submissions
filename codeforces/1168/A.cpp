#include "bits/stdc++.h"
using namespace std;
const int inf = 1e9;
int n, m;
int a[300010];

int getOpt(int x, int l, int r) {
	if(x < l) return l;
	if(x <= r) return x;
	return inf;
}

bool good(int shift) {
	int prev = -1;
	for(int i = 1; i <= n; i++) {
		if(a[i] + shift < m) {
			prev = getOpt(prev, a[i], a[i] + shift);
		} else {
			prev = min(getOpt(prev, a[i], m - 1), getOpt(prev, 0, (a[i] + shift) % m));
		}
		if(prev == inf) return false;
	}
	return true;
}

int search(int b, int e) {
	if(b == e) {
		return b;
	}
	int m = (b + e) >> 1;
	if(good(m)) {
		return search(b, m);
	} else {
		return search(m + 1, e);
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", search(0, m-1));
	return 0;
}