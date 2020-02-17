#include "bits/stdc++.h"
using namespace std;
const int maxn = 5005;
vector <int> v[maxn];
int h[maxn], f[maxn];
int l[maxn], r[maxn];
int cnt[maxn][maxn];
int n, m;
int a[maxn];
vector <int> val[maxn];
int aux[maxn];
typedef pair <int, int> pii;

const int mod = 1000000000 + 7;

int opt;
long long answer;

long long ways(int boundary, int col, int exp) {
	int ans = cnt[boundary][col];
	if(boundary < r[exp]) --ans;
	return ans;
}
void check(int x) {
	if(l[x] > n) return ;
	int bound = l[x];
	int col = f[x];
	int tot = (x > 0);
	long long res = 1;
	for(int i = 1; i <= n; i++) {
		if(col == i) {
			if(ways(bound, i, x) > 0) {
				tot += 1;
				res *= ways(bound, i, x);
				res %= mod;
			}
			continue;
		}
		int bel = 0;
		int var = 0;
		for(auto j : val[i]) {
			if(l[j] < bound) {
				var += ways(bound, i, j);
				bel += 1;
			}
			if(bound < r[j]) bel += 1;
		}
		if(var > 0) {
			tot += 2;
			res = (res * var) % mod;
		} else if (bel > 0) {
			tot += 1;
			res = (res * bel) % mod;
		}
	}
	if(opt < tot) {
		opt = tot;
		answer = res;
	} else if (opt == tot) {
		answer = (answer + res) % mod;
	}
}


void solve() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		val[a[i]].push_back(i);
	} 	
	vector <pii> can;
	for(int i = 1; i <= m; i++) {
		scanf("%d %d", f + i, h + i);
		if(val[f[i]].size() < h[i]) {
			l[i] = n + 1;
			r[i] = 0;
		} else {
			l[i] = val[f[i]][h[i] - 1];
			r[i] = val[f[i]][val[f[i]].size() - h[i]];
		}
		can.push_back(pii(r[i], f[i]));
	}
	for(int i = 1; i <= n; i++) {
		val[i].clear();
	}
	for(int i = 1; i <= m; i++) {
		val[f[i]].push_back(i);
	}
	sort(can.begin(), can.end());
	int cur = can.size() - 1;
	for(int i = n; i >= 1; i--) {
		while(cur >= 0 && can[cur].first > i) {
			aux[can[cur].second] += 1;
			--cur; 
		}
		for(int j = 1; j <= n; j++) {
			cnt[i][j] = aux[j];
		}
	}
	for(int i = 0; i <= m; i++) {
		check(i);
	}
	if(opt == 0) answer = 1;
	printf("%d %lld\n", opt, answer);
}
int main(int argc, char const *argv[])
{
	solve();
 	return 0; 
}