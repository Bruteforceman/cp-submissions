#include <bits/stdc++.h>
using namespace std;
string s[205], t[205];
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> t[i];
	}
	int q;
	cin >> q;
	while(q--) {
		int y;
		cin >> y;
		y--;
		cout << s[y % n] << t[y % m] << '\n';
	}
}