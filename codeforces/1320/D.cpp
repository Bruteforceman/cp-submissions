#include "bits/stdc++.h"
using namespace std;
string s;
int n;
vector <int> v;
vector <int> zero;
const int mod = 1000000000 + 7;
const int base = 131;
long long pw[200010];
int pos[200010];
long long pre[200010];
int cnt[200010];

int count(int l, int r) {
	if(l == 0) return cnt[r];
	else return cnt[r] - cnt[l - 1];
}
long long power(long long b, long long e) {
	if(e == 0) return 1;
	if(e & 1) return (power(b, e - 1) * b) % mod;
	long long m = power(b, e >> 1);
	return (m * m) % mod;
}
long long inverse(long long x) {
	return power(x % mod, mod - 2);
}

long long get(int l, int r) {
	int x = *lower_bound(zero.begin(), zero.end(), l);
	int y = *(--upper_bound(zero.begin(), zero.end(), r));
	if(r < x) return (r - l + 1) % 2;
	int p = pos[x];
	int q = pos[y];
	long long sum = (pre[q] - pre[p] + mod) % mod;
	sum = (sum * inverse(pw[q])) % mod;
	int sz = q - p + 1;
	if(abs(l - x) % 2 == 1) {
		sum = (sum * base + 1) % mod;
		++sz;
	}
	if(abs(r - y) % 2 == 1) {
		sum = (sum + pw[sz]) % mod;
		++sz;
	}
	return sum;
}


int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);
	cin >> n >> s;
	pw[0] = 1;
	for(int i = 1; i <= n; i++) {
		pw[i] = (pw[i - 1] * base) % mod;
	}
	zero.emplace_back(-1);
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			v.emplace_back(i);
			zero.emplace_back(i);
		} else {
			if(!v.empty() && s[v.back()] == '1') {
				v.pop_back();
			} else {
				v.emplace_back(i);
			}
		}
	} 
	zero.emplace_back(n);
	long long var = 0;
	for(int i = 0; i < v.size(); i++) {
		pos[v[i]] = i;
		if(s[v[i]] == '1') {
			var = (var + pw[i]) % mod;
		}
		pre[i] = var;
	}
	var = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') ++var;
		cnt[i] = var;
	}
	// for(auto i : v) {
	// 	cout << s[i];
	// }
	// cout << endl;
	// cout << get(1, 3) << endl;
	int q;
	cin >> q;
	while(q--) {
		int x, y, s;
		cin >> x >> y >> s;
		--x; --y;
		long long p = get(x, x + s - 1);
		long long q = get(y, y + s - 1);
		bool ans = false;
		if(count(x, x + s - 1) == count(y, y + s - 1) && p == q) ans = true; 
		cout << (ans ? "Yes\n" : "No\n");
	}
	return 0;
}