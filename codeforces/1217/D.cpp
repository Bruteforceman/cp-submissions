#include "bits/stdc++.h"
using namespace std;
#define endl '\n'
vector <int> g[5555];
int col[5555];
bool bad;

void cycle(int x) {
	col[x] = -1;
	for(auto i : g[x]) {
		if(col[i] == 0) {
			cycle(i);
		} else if (col[i] == -1) {
			bad = true;
		}
	}
	col[x] = 1;
}

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie (0);
	int n, m;
	cin >> n >> m;

	vector <pair <int, int>> v;
	for(int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		g[p].push_back(q);
		v.push_back(make_pair(p, q));
	}
	for(int i = 1; i <= n; i++) {
		if(col[i] == 0) {
			cycle(i);
		}
	}
	if(bad) {
		cout << 2 << endl;
		for(auto i : v) {
			if(i.first > i.second) cout << 1 << ' ';
			else cout << 2 << ' ';
		}
		cout << endl;
	} else {
		cout << 1 << endl;
		for(auto i : v) {
			cout << 1 << ' ';
		}
		cout << endl;
	}
	return 0;
}