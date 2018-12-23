#include "bits/stdc++.h"
using namespace std;
int deg[100010];

int main(int argc, char const *argv[])
{
	int n, s;
	scanf("%d %d", &n, &s);
	for(int i = 1; i < n; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		deg[p] += 1;
		deg[q] += 1;
	}
	int leaf = 0;
	for(int i = 1; i <= n; i++) {
		leaf += (deg[i] == 1);
	}
	double ans = (2.00 * s) / leaf;
	printf("%.10lf\n", ans);
	return 0;
}