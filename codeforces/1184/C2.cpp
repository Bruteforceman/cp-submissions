#include "bits/stdc++.h"
using namespace std;
typedef pair <int, int> pii;
int x[300010], y[300010];
int order[300010];
int t[300010 * 8];
int p[300010 * 8];
int idx;

void pushdown(int c) {
	int l = c << 1;
	int r = l + 1;
	p[l] += p[c];
	p[r] += p[c];
	t[l] += p[c];
	t[r] += p[c];
	p[c] = 0;
}
void add(int x, int y, int val, int c = 1, int b = 1, int e = idx) {
	if(x <= b && e <= y) {
		t[c] += val;
		p[c] += val;
		return ;
	}
	if(y < b || e < x) return ;
	pushdown(c);
	int l = c << 1;
	int r = l + 1;
	int m = (b + e) >> 1;
	add(x, y, val, l, b, m);
	add(x, y, val, r, m + 1, e);
	t[c] = max(t[l], t[r]);
}

int main(int argc, char const *argv[])
{
	int n, r;
	scanf("%d %d", &n, &r);
	r *= 2;

	map <int, int> cmp;
	vector <pii> v;
	for(int i = 1; i <= n; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		x[i] = p + q;
		y[i] = p - q;
		cmp[y[i]];
		cmp[y[i] + r];
		v.push_back(pii(x[i], y[i]));
		// cout << x[i] << ' ' << y[i] << endl;
	}
	sort(v.begin(), v.end());

	for(auto &i : cmp) {
		i.second = ++idx;
	}

	int l = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		while(l < i && v[i].first - v[l].first > r) {
			int q = v[l].second;
			add(cmp[q], cmp[q + r], -1);
			++l;
		}
		int q = v[i].second;
		add(cmp[q], cmp[q + r], 1);
		ans = max(ans, t[1]);
	}
	printf("%d\n", ans);
	return 0;
}