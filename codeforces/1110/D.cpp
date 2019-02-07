#include "bits/stdc++.h"
using namespace std;
int cnt[1000010];
int dp[3][3][1000010];
const int maxn = 1000000 + 3;

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x] += 1;
	}
	for(int x = 3; x < maxn; x++) {
		for(int p = 0; p <= 2; p++) {
			for(int q = 0; q <= 2; q++) {
				for(int i = 0; i <= cnt[x] && i <= 2; i++) {
					if(cnt[x - 2] >= p + q + i) {
						dp[q][i][x + 1] = max(dp[q][i][x + 1], i + dp[p][q][x] + (cnt[x - 2] - p - q - i) / 3);
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= 2; i++) {
		for(int j = 0; j <= 2; j++) {
			ans = max(ans, dp[i][j][maxn]);
		}
	}
	printf("%d\n", ans);
	return 0;
}