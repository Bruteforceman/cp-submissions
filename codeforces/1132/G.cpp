#include "bits/stdc++.h"
using namespace std;
int t[1000010 * 4];
int p[1000010 * 4];
int n;

void pushdown(int c) {
	int l = c << 1;
	int r = l + 1;
	p[l] += p[c];
	p[r] += p[c];
	t[l] += p[c];
	t[r] += p[c];
	p[c] = 0; 
}

void update(int x, int y, int val, int c = 1, int b = 1, int e = n) {
	if(x <= b && e <= y) {
		t[c] += val;
		p[c] += val;
		return ;
	} 
	if (y < b || e < x) return ;
	pushdown(c);
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	update(x, y, val, l, b, m);
	update(x, y, val, r, m+1, e);
	t[c] = max(t[l], t[r]);
}
int query(int x, int y, int c = 1, int b = 1, int e = n) {
	if(x <= b && e <= y) {
		return t[c];
	}
	if(y < b || e < x) return 0;
	pushdown(c);
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	return max(query(x, y, l, b, m), query(x, y, r, m+1, e));
}

int a[1000010];
int ans[1000010];

int main(int argc, char const *argv[])
{
	int k;
	scanf("%d %d", &n, &k);

	vector <int> v;
	v.emplace_back(0);
	a[0] = INT_MAX;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		while(!v.empty() && a[v.back()] < a[i]) {
			v.pop_back();
		}
		update(v.back() + 1, i, 1);
		// cout << "add: " << v.back() + 1 << ' ' << i << endl;
		v.emplace_back(i);
		if(i >= k) {
			ans[i] = query(i - k + 1, i);
		} 
	}
	for(int i = k; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}