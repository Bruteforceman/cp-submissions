#include "bits/stdc++.h"
using namespace std;
const int mod = 998244353;

int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d", &n, &k);
	vector <pair <int, int>> p (n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	vector <int> can;

	long long opt = 0;
	long long ans = 1;
	for(int i = 0; i < k; i++) {
		can.push_back(p[i].second);
		opt += p[i].first;
	}
	sort(can.begin(), can.end());
	for(int i = 1; i < k; i++) {
		ans *= can[i] - can[i - 1];
		ans %= mod;
	}

	printf("%lld %lld\n", opt, ans);
	return 0;
}