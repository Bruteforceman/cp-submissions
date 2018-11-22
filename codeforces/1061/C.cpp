#include "bits/stdc++.h"
using namespace std;
vector <int> v[1000010];
int dp[100010];
const int mod = 1000000000 + 7;
int a[100010];

int main(int argc, char const *argv[])
{
	for(int i = 1; i <= 100000; i++) {
		for(int j = i; j <= 1000000; j += i) {
			v[j].push_back(i);
		}
	}
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		vector <int> add;
		for(auto j : v[a[i]]) {
			add.push_back(dp[j - 1]);
		}	
		for(size_t j = 0; j < v[a[i]].size(); j++) {
			dp[v[a[i]][j]] += add[j];
			dp[v[a[i]][j]] %= mod;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += dp[i];
		ans %= mod;
	}
	printf("%d\n", ans);
	return 0;
}