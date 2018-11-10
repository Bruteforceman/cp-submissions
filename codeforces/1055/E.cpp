#include "bits/stdc++.h"
using namespace std;
#define left dsdf

int n, s, m, k;
int a[1555];
int b[1505];

bool bad[1555];
int l[1555], r[1555];
int left[1555];

typedef pair <int, int> pii;
int dp[1505][1505];
int p[1505];

bool good(int x) {
	for(int i = 1; i <= n; i++) {
		p[i] = p[i - 1] + (a[i] <= x);
	}
	for(int i = 1; i <= m; i++) {
		deque <pii> Q;
		Q.push_back(pii(0, 0));
		for(int j = 1; j <= n; j++) {
			if(left[j] == -1) {
				dp[i][j] = dp[i][j - 1];
			} else {
				while(!Q.empty() && Q.front().first < left[j] - 1) {
					Q.pop_front();
				}
				dp[i][j] = max(dp[i][j - 1], p[j] + Q.front().second);
			}
			while(!Q.empty() && Q.back().second <= dp[i - 1][j] - p[j]) {
				Q.pop_back();
			}
			Q.push_back(pii(j, dp[i - 1][j] - p[j]));
		}
	}
	return dp[m][n] >= k;
}

int search(int l, int r) {
	if(l == r) {
		return good(b[l]) ? b[l] : -1;
	}
	int mid = (l + r) >> 1;
	if(good(b[mid])) return search(l, mid);
	else return search(mid + 1, r);
} 
int main(int argc, char const *argv[])
{
	scanf("%d %d %d %d", &n, &s, &m, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= s; i++) {
		scanf("%d %d", &l[i], &r[i]);
	} 
	for(int i = 1; i <= s; i++) {
		for(int j = 1; j <= s; j++) {
			if(i != j) {
				if(l[i] == l[j] && r[i] == r[j]) {
					if(i < j) {
						bad[i] = true;
					}
				} else if(l[j] <= l[i] && r[i] <= r[j]) {
					bad[i] = true;
				}
			} 
		}
	}
	memset(left, -1, sizeof left);
	int cnt = 0;
	for(int i = 1; i <= s; i++) {
		if(!bad[i]) {
			left[r[i]] = l[i];
			++cnt;
		}
	}
	m = min(m, cnt);
	printf("%d\n", search(1, n));
	return 0;
}