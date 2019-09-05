#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		int x, y, e;
		cin >> x >> y >> e;
		int mn;
		if((y - x + e) < 0) {
			mn = 0;
		} else {
			mn = (y - x + e) / 2;
			mn += 1;
		}
		cout << max(0, e - mn + 1) << endl;
	}
	return 0;
}