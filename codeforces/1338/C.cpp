#include "bits/stdc++.h"
using namespace std;
const long long maxQ = 1e16;
using pii = pair <long long, long long>;
string base4(long long x) {
	string s;
	for(int i = 0; i < 30; i++) {
		char y = '0' + int(x % 4);
		s += y;
		x /= 4;
	}
	// reverse(s.begin(), s.end());
	return s;
}
int main(int argc, char const *argv[])
{
	// set <int> s;
	// for(int i = 1; i <= 100; i++) {
	// 	int a = 1, b = 1;
	// 	while(s.count(a)) ++a;
	// 	s.insert(a);
	// 	while(s.count(b) || s.count(a ^ b)) ++b;
	// 	s.insert(b);
	// 	s.insert(a ^ b);
	// 	// cout << bitset<10>(a) << ' ' << bitset<10>(b) << ' ' << bitset<10>(a ^ b) << endl;
	// 	// cout << i << ' ' << bitset<10>(a) << ' ' << base4(b) << ' ' << base4(a ^ b) << endl;
	// 	// cout << (a^b) << ' ';
	// }
	// // cout << "here" << endl;
	vector <pii> v;
	map <char, int> mp {{'0', 0}, {'1', 2}, {'2', 3}, {'3', 1}};
	long long cur = 1;
	long long p2 = 1;
	while(cur <= maxQ) {
		v.emplace_back(cur, p2);
		cur += p2;
		p2 *= 4;
	}
	reverse(v.begin(), v.end());
	auto A = [&] (long long x) {
		for(auto i : v) {
			if(i.first <= x) {
				return i.second + (x - i.first);
			}
		}
		return 0LL;
	};
	auto B = [&]  (long long x) {
		string p = base4(A(x));
		long long q = 1, ans = 0;
		for(char i : p) {
			ans += q * mp[i];
			q *= 4;
		}
		return ans;
	};
	auto C = [&] (long long x) {
		long long a = A(x);
		long long b = B(x);
		return a ^ b;
	};
	int t;
	scanf("%d", &t);
	while(t--) {
		long long n;
		scanf("%lld", &n);
		long long i = (n + 2) / 3;
		long long ans = 0;
		if(n % 3 == 1) {
			ans = A(i);
		} else if (n % 3 == 2) {
			ans = B(i);
		} else {
			ans = C(i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}