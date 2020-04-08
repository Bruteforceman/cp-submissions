#include "bits/stdc++.h"
using namespace std;
int a[200010];
long long p[200010];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		p[i] = p[i - 1] + a[i];
	}
	int l = 0;
	long long ans = 0;
	map <long long, int> cnt;
	for(int i = 0; i <= n; i++) {
		cnt[p[i]] += 1;
		while(cnt[p[i]] > 1) {
			cnt[p[l++]] -= 1;
		}
		ans += i - l;
	}
	printf("%lld\n", ans);
	return 0;
}