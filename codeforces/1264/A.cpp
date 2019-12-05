#include "bits/stdc++.h"
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	map <int, int> cnt;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[-x] += 1;
	}
	int ans = 0, g = 0;
	vector <int> v;
	for(auto i : cnt) {
		if(i.second + ans <= (n / 2)) {
			ans += i.second;
			v.push_back(i.second);
		} else break;
	}
	if(v.empty()) {
		printf("0 0 0\n");
		return ;
	}
	g = v[0];
	int cur = 1;
	int s = 0, b = 0;
	while(cur < v.size() && s <= g) {
		s += v[cur++];
	}
	while(cur < v.size()) {
		b += v[cur++];
	}
	if(g < s && g < b && g > 0) {
		printf("%d %d %d\n", g, s, b);
	} else {
		printf("0 0 0\n");
	}
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