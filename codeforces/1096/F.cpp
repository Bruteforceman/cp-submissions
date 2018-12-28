#include "bits/stdc++.h"
using namespace std;
int n;
bool vis[200010];
int a[200010];
long long fac[200010];

const int mod = 998244353;

long long modpow(long long b, long long e) {
	if(e == 0) return 1;
	if(e & 1) return (modpow(b, e - 1) * b) % mod;
	long long m = modpow(b, e >> 1);
	return (m * m) % mod;
}
long long inverse(long long x) {
	return modpow(x, mod - 2);
}
long long nC2(long long x) {
	return ((x * (x-1)) / 2) % mod;
}

struct fenwick {
	int t[200010];
    fenwick () {
    	memset(t, 0, sizeof t);
	}
	void update(int x, int val) {
		for(int i = x; i <= n; i += i & (-i)) {
			t[i] += val;
		}
	}
	int query(int x) {
		int sum = 0;
		for(int i = x; i > 0; i -= i & (-i)) {
			sum += t[i];
		}
		return sum;
	}
	int query(int x, int y) {
		if(x > y) return 0;
		return query(y) - query(x-1);
	}
} T, G;

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	fac[0] = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] != -1) {
			vis[a[i]] = true;
		}
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}
	int total = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			G.update(i, 1);
			++total;
		}
	}
	long long ans = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] != -1) {
			if(cnt) {
				ans += G.query(a[i] + 1, n) * ((cnt * fac[total - 1]) % mod);
				ans %= mod;
			}
		} else {
			++cnt;
		}
	}
	cnt = 0;
	for(int i = n; i >= 1; i--) {
		if(a[i] != -1) {
			if(cnt) {
				ans += G.query(1, a[i] - 1) * ((cnt * fac[total - 1]) % mod);
				ans %= mod;
			}
		} else {
			++cnt;
		}
	}

	ans += nC2(total) * ((fac[total] * inverse(2)) % mod);
	ans %= mod;
	ans *= inverse(fac[total]);
	ans %= mod;

	for(int i = 1; i <= n; i++) {
		if(a[i] != -1) {
			ans += T.query(a[i] + 1, n);
			ans %= mod;
			T.update(a[i], 1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}