#include "bits/stdc++.h"
using namespace std;

inline long long sq(long long x) {
	return x * x;
}
inline long long cost(long long x, long long y, long long z) {
	return sq(x - y) + sq(y - z) + sq(z - x);
}
long long solve(vector <int> &a, vector <int> &b, vector <int> &c) {
	vector <int> prev (b.size()), nxt (b.size());
	int l = 0;
	int var = -1;
	for(int i = 0; i < b.size(); i++) {
		while(l < a.size() && a[l] <= b[i]) {
			var = a[l];
			++l;
		}
		prev[i] = var;
	}
	int r = c.size() - 1; 
	var = -1;
	for(int i = b.size() - 1; i >= 0; i--) {
		while(r >= 0 && c[r] >= b[i]) {
			var = c[r];
			--r;
		}
		nxt[i] = var;
	}
	long long ans = LLONG_MAX;
	for(int i = 0; i < b.size(); i++) {
		if(nxt[i] == -1 || prev[i] == -1) continue;
		ans = min(ans, cost(prev[i], b[i], nxt[i]));
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		vector <int> a (p), b (q), c (r);
		for(int i = 0; i < p; i++) {
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < q; i++) {
			scanf("%d", &b[i]);
		}
		for(int i = 0; i < r; i++) {
			scanf("%d", &c[i]);
		}
		vector <vector <int>> v ({a, b, c});
		for(auto &i: v) {
			sort(i.begin(), i.end());
		}
		vector <int> perm ({0, 1, 2});
		long long ans = LLONG_MAX;
		do {
			ans = min(ans, solve(v[perm[0]], v[perm[1]], v[perm[2]]));
		} while(next_permutation(perm.begin(), perm.end()));
		printf("%lld\n", ans);
	}
	return 0;
}