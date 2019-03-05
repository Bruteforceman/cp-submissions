#include "bits/stdc++.h"
using namespace std;
int l[5555], r[5555];
int n, q;
int P[5555];
int cnt[5555];

int solve(int x) {
	memset(cnt, 0, sizeof cnt);
	for(int i = 1; i <= q; i++) {
		if(i != x) {
			cnt[l[i]] += 1;
			cnt[r[i] + 1] -= 1;
		}
	}
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
		P[i] = (cnt[i] == 1);
		P[i] += P[i - 1];
		tot += (cnt[i] > 0);
	}
	int opt = n;
	for(int i = 1; i <= q; i++) {
		if(i != x) {
			opt = min(opt, P[r[i]] - P[l[i] - 1]);
		}
	}
	return tot - opt;
} 

int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= q; i++) {
		scanf("%d %d", &l[i], &r[i]);
	}
	int ans = 0;
	for(int i = 1; i <= q; i++) {
		ans = max(ans, solve(i));
	}
	printf("%d\n", ans);
	return 0;
}