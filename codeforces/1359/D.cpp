#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e5 + 10;
int pre[maxn], a[maxn];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	a[0] = INT_MAX;
	vector <pair <int, int>> v;
	v.emplace_back(0, 0);
	multiset <int> s;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int val = pre[i - 1];
		while(a[v.back().first] <= a[i]) {
			val = min(val, v.back().second);
			s.erase(s.find(a[v.back().first] + v.back().second));
			v.pop_back();
		}
		v.emplace_back(i, val);
		s.insert(a[i] + val);
		ans = max(ans, pre[i] - *s.begin());
	}
	printf("%d\n", ans);
	return 0;
}