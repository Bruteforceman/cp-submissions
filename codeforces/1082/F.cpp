#include "bits/stdc++.h"
using namespace std;
int t[555][30];
int val[555];
int h[555];
int node;

void insert(string s, int x) {
	int cur = 0;
	int height = 0;
	for(int i = 0; i < s.size(); i++) {
		int c = s[i] - '0';
		if(t[cur][c] == -1) {
			t[cur][c] = ++node;
		}
		cur = t[cur][c];
		h[cur] = ++height;
	}
	val[cur] += x;
}

int dp[555][555][12];
int piv;
int last;
int mem[26][11];
const int inf = 1e9;
int k;

int fn(int now, int take) {
	if(now == 26) {
		if(h[piv] == last && last > 0) {
			if(take == 0) return inf;
			else return 0;
		} 
		else return val[piv] * (h[piv] - last);
	}
	if(mem[now][take] != -1) return mem[now][take];
	int ans;
	if(t[piv][now] != -1) {
		ans = inf;
		int nxt = t[piv][now];
		for(int x = 0; x <= take; x++) {
			ans = min(ans, fn(now + 1, take - x) + dp[nxt][last][x]);
			ans = min(ans, fn(now + 1, take - x) + dp[nxt][h[nxt]][x]);
		}
	} else {
		ans = fn(now + 1, take);
	}
	return mem[now][take] = ans;
}

void dfs(int cur) {
	for(int i = 0; i < 26; i++) {
		if(t[cur][i] != -1) {
			dfs(t[cur][i]);
		}
	}
	piv = cur;
	for(last = 0; last <= h[cur]; last++) {
		memset(mem, -1, sizeof mem);
		for(int x = 0; x <= k; x++) {
			dp[cur][last][x] = fn(0, x);
		}
	}
} 

int main(int argc, char const *argv[])
{
	memset(t, -1, sizeof t);

	int n;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		string s;
		int x;
		cin >> s >> x;
		insert(s, x);
	}
	dfs(0);
	printf("%d\n", dp[0][0][k]);
	return 0;
}