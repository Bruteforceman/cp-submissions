#include "bits/stdc++.h"
using namespace std;
int a[200010];
long long dp[200010];

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}	
	map <int, long long> opt;
	long long ans = 0;
	for(int i = n; i >= 1; i--) {
		dp[i] = a[i];
		if(opt.find(i - a[i]) != opt.end()) {
			dp[i] = max(dp[i], a[i] + opt[i - a[i]]);
		}
		opt[i - a[i]] = max(opt[i - a[i]], dp[i]);
		ans = max(ans, dp[i]);
	}	
	printf("%lld\n", ans);
	return 0;
}