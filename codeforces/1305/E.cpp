#include "bits/stdc++.h"
using namespace std;
int dp[100010];
int cnt[100010];
int sz;
 
void construct(int n, int m) {
	if(5000 * 5000 <= m) {
		printf("-1\n");
		return ;
	}
	int start = 1;
	vector <int> v, ans;
	while(m > 0) {
		int r = upper_bound(dp, dp + sz, m) - dp - 1;
		m -= dp[r];
		v.push_back(r);
		cout << r << ' ' << dp[r] << endl;
	}
	for(int i : v) {
		int cnt = i;
		while(cnt--) {
			ans.push_back(start++);
		}
		start = (start - 1) * 2;
	}
	if(ans.size() > n) {
		printf("-1\n");
		return ;
	}
	int now = 1000000000 - 1;
	while(ans.size() < n) {
		ans.push_back(now);
		now -= 2;
	}
	sort(ans.begin(), ans.end());
	for(auto i : ans) {
		cout << i << ' ';
	}
	cout << endl;
}
 
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	bool good = false;
	vector <int> ans;
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + cnt[i];
		if(dp[i] >= m) {
			int now = i;
			while(dp[i - 1] + cnt[now] > m) {
				++now;
			}
			ans.push_back(now);
			good = true;
			break;
		}
		ans.push_back(i);
		for(int j = 1; j < i; j++) {
			cnt[j + i] += 1;
		}
	}
	if(!good) {
		printf("-1\n");
		exit(0);
	}
	int now = 1000000000;
	int diff = ans.back() + 1;
	while(ans.size() < n) {
		ans.push_back(now);
		now -= diff;
	}
	sort(ans.begin(), ans.end());
	for(auto i : ans) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}