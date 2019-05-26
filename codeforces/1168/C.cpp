#include "bits/stdc++.h"
using namespace std;
const int logn = 19;
int dp[20][300010];
int last[20];
int a[300010];

int query(int x, int y) {
	int opt = 0;
	for(int i = 0; i <= logn; i++) {
		if((a[x] >> i) & 1) {
			opt = max(opt, dp[i][y]);
		}
	}
	return opt >= x;
} 

int main(int argc, char const *argv[])
{
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= logn; j++) {
			if((a[i] >> j) & 1) {
				dp[j][i] = i;
			} else {
				for(int k = 0; k <= logn; k++) {
					if((a[i] >> k) & 1) {
						dp[j][i] = max(dp[j][i], dp[j][last[k]]);
					}
				}
			}
		}
		for(int j = 0; j <= logn; j++) {
			if((a[i] >> j) & 1) {
				last[j] = i;
			}
		}
	}
	while(q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if(query(x, y)) {
			printf("Shi\n");
		} else {
			printf("Fou\n");
		}
	}
	return 0;
}