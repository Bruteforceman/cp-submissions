#include "bits/stdc++.h"
using namespace std;

int dp[111][10005];
int fn[111][10005];
int a[111];
int n;
const int maxn = 10000;

// void outp() {
// 	for(int i = 0; i <= n; i++) {
// 		for(int j = 0; j <= 10000; j++) {
// 			if(O[i][j] == 1) {
// 				cout << i << ' ' << j << endl;
// 			}
// 		}
// 	}
// }

int main(int argc, char const *argv[])
{
	cin >> n;
	map <int, int> mp;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[0][0] = a[i];
		mp[a[i]] += 1;
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= maxn; k++) {
				fn[j][k] = dp[j][k];
				if(fn[j][k] < 0) continue;
				if(k >= a[i]) {
					if(dp[j - 1][k - a[i]] < 0) {
						fn[j][k] = -1;
					} else if (dp[j - 1][k - a[i]] > 0) {
						if(dp[j - 1][k - a[i]] == a[i]) {
							fn[j][k] = a[i];
						} else {
							fn[j][k] = -1;
						}
					}
				}
			}
		}
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= maxn; k++) {
				dp[j][k] = fn[j][k];
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= maxn; j++) {
			if(dp[i][j] > 0) {
				int p = dp[i][j];
				mp[p] -= i;
				int tot = i;
				int cnt = 0;
				for(auto k : mp) {
					if(k.second > 0) {
						++cnt;
					}
				}
				mp[p] += i;	
				if(cnt == 1) tot = n;
				ans = max(ans, tot);
			}
		}
	}
	cout << ans << endl;
	return 0;
}