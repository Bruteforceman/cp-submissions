#include "bits/stdc++.h"
using namespace std;
int mem[3][105];
int v[3];
long long a[300010];
const int maxLow = 50;
const int maxUp = 100;
const int maxper = 100;
int p[3];

int dp(int cur, int last) {
	if(cur == 0) return 0;
	if(mem[last][cur] != -1) return mem[last][cur];
	set <int> s;
	for(int i = 0; i <= 2; i++) {
		if(i == 0 || i != last) s.insert(dp(max(0, cur - v[i]), i));
	}
	int ans = 0;
	while(s.count(ans)) ++ans;
	return mem[last][cur] = ans;
}
int get(long long cur, int last) {
	if(cur <= maxUp) return dp(cur, last);
	int mod = cur % p[last];
	cur = maxUp;
	while(cur % p[last] != mod) {
		--cur;
	}
	return dp(cur, last);
}
void solve() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 3; i++) scanf("%d", v + i);
	memset(mem, -1, sizeof mem);
	for(int last = 0; last < 3; last++) {
		for(int k = 1; ; k++) {
			bool bad = false;
			for(int i = maxUp; i >= maxLow; i--) {
				if(dp(i, last) != dp(i - k, last)) {
					bad = true;
					break;
				}
			}
			if(!bad) {
				p[last] = k;
				break;
			}
		}
	}
	int nimber = 0;
	for(int i = 0; i < n; i++) {
		scanf("%lld", a + i);
		nimber ^= get(a[i], 0);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			int opt = nimber ^ get(max(0LL, a[i] - v[j]), j) ^ get(a[i], 0);
			if(opt == 0) ++ans;
		}
	}
	printf("%d\n", ans);
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}
	return 0;
}