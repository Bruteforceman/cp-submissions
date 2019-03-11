#include "bits/stdc++.h"
using namespace std;
typedef pair <int, int> pii;

vector <int> v[300010];
int p[300010];
int need[300010];

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for(int i = 1; i <= m; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		v[p].emplace_back(q);
	}	
	int ans = 0;
	need[p[n]] = 1;
	int tot = 1;
	for(int i = n-1; i >= 1; i--) {
		int cnt = 0;
		for(auto j : v[p[i]]) {
			if(need[j] == 1) {
				++cnt;
			}
		}
		if(cnt == tot) {
			++ans;
		} else {
			++tot;
			need[p[i]] = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}