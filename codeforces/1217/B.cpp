#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie (0);

	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		int mx = 0;
		int mxd = 0;
		for(int i = 0; i < n; i++) {
			int d, h;
			cin >> d >> h;
			mxd = max(mxd, d - h);
			mx = max(mx, d);
		}
		x -= mx;
		if(x <= 0) {
			cout << 1 << endl;
		} else if (mxd > 0) {
			cout << ((x + mxd - 1) / mxd) + 1 << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}