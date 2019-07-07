#include "bits/stdc++.h"
using namespace std;
int adj[111][111];
int xp[100010], a[100010], f[100010], p[100010];
int xb[100010], d[100010], g[100010];
const int inf = 1e9;
long long ans[100010];

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);

	int s, b;
	cin >> s >> b;

	vector <pair <int, int>> v;
	for(int i = 1; i <= s; i++) {
		cin >> a[i];
		v.emplace_back(a[i], i);
	}
	for(int i = 1; i <= b; i++) {
		cin >> d[i] >> g[i];
		v.emplace_back(d[i], -i);
	}
	sort(v.begin(), v.end());
	long long sum = 0;
	for(auto i : v) {
		int id = abs(i.second);
		if(i.second > 0) {
			ans[id] = sum;
		} else {
			sum += g[id];
		}
	}
	for(int i = 1; i <= s; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}