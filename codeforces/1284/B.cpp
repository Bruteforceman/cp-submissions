#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector <int> mn, mx;
	long long ans = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		int l;
		scanf("%d", &l);
		int p = INT_MIN;
		int q = INT_MAX;
		bool good = false;		
		while(l--) {
			int x;
			scanf("%d", &x);
			if(q < x) {
				good = true;
			}
			p = max(p, x);
			q = min(q, x);
		}
		if(!good) {
			mn.push_back(q);
			mx.push_back(p);
		} else {
			++cnt;		
		}
	}
	sort(mn.begin(), mn.end());
	sort(mx.begin(), mx.end());
	int l = 0;
	for(int i = 0; i < mx.size(); i++) {
		while(l < mn.size() && mn[l] < mx[i]) {
			++l;
		}
		ans += l;
	}
	ans += 2LL * cnt * (n - cnt);
	ans += 1LL * cnt * cnt; 
	printf("%lld\n", ans);
	return 0;
}