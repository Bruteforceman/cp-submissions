#include "bits/stdc++.h"
using namespace std;
int a[100010], b[100010];

int main(int argc, char const *argv[])
{
	long long ans = 0;

	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ans += 1LL * m * a[i];
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		ans += b[i];
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	if(a[n] < b[1]) {
		ans -= 1LL * (m - 1) * a[n];
		ans -= a[n - 1];
	} else if (a[n] == b[1]) {
		ans -= 1LL * m * a[n];
	} else {
		ans = -1;
	}
	printf("%lld\n", ans);
	return 0;
}