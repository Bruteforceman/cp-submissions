#include "bits/stdc++.h"
using namespace std;
int dp[500010], vis[500010];
int search(int b, int e, int value) {
	if(b == e) return b;
	int m = (b + e) >> 1;
	if(dp[m] >= value) return search(b, m, value);
	else return search(m + 1, e, value);
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		vis[i] = true;
	}
	int cnt = 0;
	for(int i = n; i >= 1; i--) {
		dp[i] = n - cnt;
		for(int j = i + i; j <= n; j += i) {
			cnt += vis[j];
			vis[j] = 0;
		}
	}
	for(int i = 2; i <= n; i++) {
		int answer = search(1, n, i);
		printf("%d ", answer);
	}
	printf("\n");
	return 0;
}