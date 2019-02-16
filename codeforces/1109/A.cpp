#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	map <int, int> cnt[2];
	int cur = 0;
	long long ans = 0;
	cnt[0][0] += 1;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cur ^= x;
		ans += cnt[i & 1][cur];
		cnt[i & 1][cur] += 1;
	}
	printf("%lld\n", ans);
	return 0;
}