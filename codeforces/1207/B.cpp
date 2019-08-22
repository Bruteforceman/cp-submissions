#include "bits/stdc++.h"
using namespace std;
int a[55][55], b[55][55];

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector <pair <int, int>> v;
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < m - 1; j++) {
			int c = (a[i][j] & a[i][j + 1] & a[i + 1][j] & a[i + 1][j + 1]);
			if(c == 1) {
				b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
				v.push_back(make_pair(i + 1, j + 1));
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] != b[i][j]) {
				cout << -1 << endl;
				exit(0);
			}
		}
	}
	cout << v.size() << endl;
	for(auto i : v) {
		cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}