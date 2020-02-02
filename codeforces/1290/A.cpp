#include "bits/stdc++.h"
using namespace std;
int a[3505];
int n, m, k;
const int inf = 1000000000;
int solve() {
	k = min(k, m - 1);
	int sz = n - m + 1;
	int ans = 0;
	for(int p = 0; p <= k; p++) {
		int q = k - p;
		int opt = INT_MAX;
		for(int i = p + 1; i + sz - 1 <= n - q; i++) {
			opt = min(opt, max(a[i], a[i + sz - 1]));
		}
		ans = max(ans, opt);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		printf("%d\n", solve());
	}
	return 0;
}