#include "bits/stdc++.h"
using namespace std;
int cnt[5555];
int opt[5555];
int n;
int dist(int p, int q) {
	return (q - p + n) % n;
}
int main(int argc, char const *argv[])
{
	int m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		--p;
		--q;
		if(cnt[p]) {
			opt[p] = min(opt[p], dist(p, q));
		} else {
			opt[p] = dist(p, q);
		}
		++cnt[p];
	}
	for(int i = 0; i < n; i++) {
		int ans = 0;
		for(int j = 0; j < n; j++) {
			if(cnt[j]) {
				ans = max(ans, (cnt[j] - 1) * n + dist(i, j) + opt[j]); 
			}
		}
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}