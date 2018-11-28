#include "bits/stdc++.h"
using namespace std;
int a[500010];

int main(int argc, char const *argv[])
{
	int n, c;
	scanf("%d %d", &n, &c);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] = c - a[i];
	}
	int ans = 0;
	int cnt = 0;
	map <int, int> mp;
	map <int, int> tot;
	for(int i = 1; i <= n; i++) {
		if(a[i] == 0) {
			++cnt;
		} else {
			mp[a[i]] = min(mp[a[i]], tot[a[i]] - cnt);
			tot[a[i]] += 1;
			ans = max(ans, tot[a[i]] - cnt - mp[a[i]]);
		}
	}
	ans += cnt;
	printf("%d\n", ans);
	return 0;
}