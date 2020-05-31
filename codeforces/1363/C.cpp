#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e5;
int deg[maxn];
void solve() {
	int n, x;
	scanf("%d %d", &n, &x);
	for(int i = 1; i <= n; i++) deg[i] = 0;
	for(int i = 1; i < n; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		deg[p] += 1;
		deg[q] += 1;
	}
	if(deg[x] <= 1) {
		printf("Ayush\n");
	} else {
		if(n % 2 == 1) {
			printf("Ashish\n");
		} else {
			printf("Ayush\n");
		}
	}
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}
	return 0;
}