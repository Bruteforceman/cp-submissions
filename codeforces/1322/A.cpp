#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int val = 0;
	int ans = 0;
	int last = 0;
	for(int i = 0; i < n; i++) {
		last = val;
		val += (s[i] == '(') ? 1 : -1;
		if(val < 0) ++ans;
		else if (val == 0 && last < 0) ++ans;
	}
	if(val != 0) {
		cout << -1 << endl;
	}
	else cout << ans << endl;
	return 0;
}