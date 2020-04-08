#include "bits/stdc++.h"
using namespace std;
char a[111][111];
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				a[i][j] = "BW"[(i + j) & 1];
			}
		}
		bool done = (n * m) % 2;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j] == 'W' && !done) {
					done = true;
					a[i][j] = 'B';
				} 
				cout << a[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}