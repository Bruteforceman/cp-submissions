#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int t, f, p;
		cin >> t >> f >> p;
		int h, c;
		cin >> h >> c;
		if(c > h) {
			swap(c, h);
			swap(f, p);
		}
		int tot = (t / 2);
		int ans = 0;
		ans += min(tot, f) * h;
		tot -= min(tot, f);
		ans += min(tot, p) * c;
		cout << ans << endl;
	}
	return 0;
}