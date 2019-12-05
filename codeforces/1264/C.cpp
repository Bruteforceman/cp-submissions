#include "bits/stdc++.h"
using namespace std;
const int mod = 998244353;
long long pi[200010];
int n;

long long modpow(long long b, int e) {
	if(e == 0) return 1;
	if(e & 1) return (modpow(b, e - 1) * b) % mod;
	long long m = modpow(b, e >> 1);
	return (m * m) % mod;
}
long long inverse(long long x) {
	return modpow(x % mod, mod - 2);
}

typedef pair <long long, long long> pll;
pll t[200010 * 4];

pll combine(pll p, pll q, int mid) {
	long long a = (p.first * q.first) % mod;
	a = (a * pi[mid]) % mod;
	long long b = (q.first * p.second - q.first) % mod;
	b = (b * pi[mid]) % mod;
	b = (b + q.second) % mod;
	return pll(a, b);
}

pll query(int x, int y, int c = 1, int b = 1, int e = n + 1) {
	if(x <= b && e <= y) {
		return t[c];
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	if(y <= m) return query(x, y, l, b, m);
	else if (m < x) return query(x, y, r, m + 1, e);
	else return combine(query(x, m, l, b, m), query(m + 1, y, r, m + 1, e), m);
}
void build(int c = 1, int b = 1, int e = n + 1) {
	if(b == e) {
		t[c] = pll(1, 0);
		return ;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	build(l, b, m);
	build(r, m + 1, e);
	t[c] = combine(t[l], t[r], m);
}
long long value(int l, int r) {
	pll p = query(l, r);
	return -p.second;
} 

set <int> s;
long long ans;

void update(int x) {
	if(s.find(x) == s.end()) {
		auto it = s.upper_bound(x);
		int r = *it;
		int l = *(--it);
		ans -= value(l, r);
		ans += value(l, x) + value(x, r);
		ans %= mod;
		s.insert(x);
	} else {
		s.erase(x);
		auto it = s.upper_bound(x);
		int r = *it;
		int l = *(--it);
		ans += value(l, r);
		ans -= value(l, x) + value(x, r);
		ans %= mod;
	}
	ans %= mod;
	ans = (ans + mod) % mod;
}
int main(int argc, char const *argv[])
{
	int q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &pi[i]);
		pi[i] = (100LL * inverse(pi[i])) % mod;
	}
	build();
	s.insert(1);
	s.insert(n + 1);
	ans = value(1, n + 1);
	// cout << (value(1, 3) + mod) % mod << endl;
	// exit(0);
	while(q--) {
		int x;
		scanf("%d", &x);
		update(x);
		printf("%lld\n", ans);
	}
	return 0;
}