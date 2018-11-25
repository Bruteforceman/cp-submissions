#include "bits/stdc++.h"
using namespace std;

typedef pair <int, int> pii;

int n, m;
int p[3111];
int a[3111];
bool vis[3111];

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n+n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		p[x] = y;
		p[y] = x;
	}

	int t;
	cin >> t;
	t %= 2;

	int last = 0;

	while(true) {
		bool good = false;
		for(int i = 1; i <= n+n; i++) {
			if(vis[i] == false) {
				good = true;
				break;
			}
		}
		if(good == false) break;

		if(t == 1) {
			if(p[last] > 0 && !vis[p[last]]) {
				cout << p[last] << endl;
				last = p[last];
			} else {
				int opt = -1;
				for(int i = 1; i <= n+n; i++) {
					if(!vis[i] && p[i] > 0) {
						if(opt == -1 || a[i] > a[opt]) {
							opt = i;
						}
					}		
				}
				if(opt == -1) {
					opt = -1;
					for(int i = 1; i <= n+n; i++) {
						if(!vis[i]) {
							if(opt == -1 || a[i] > a[opt]) {
								opt = i;
							}
						}
					}
				}
				cout << opt << endl;
				last = opt;
			}
		} else {
			int x;
			cin >> x;
			last = x;
		}
		vis[last] = true;
		t ^= 1;
	}
	return 0;
}