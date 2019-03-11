#include "bits/stdc++.h"
using namespace std;
int a[555][555];
int b[555][555];
multiset <int> P[555][555];
multiset <int> Q[555][555];

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int x = i;
			int y = j;
			while(x < n && y > 1) {
				++x;
				--y;
			}
			P[x][y].insert(a[i][j]);
			Q[x][y].insert(b[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(P[i][j] != Q[i][j]) {
				printf("NO\n");
				exit(0);
			}
		}
	}
	printf("YES\n");
	return 0;
}