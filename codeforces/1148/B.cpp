#include "bits/stdc++.h"
using namespace std;
int a[300010], b[300010];


int main(int argc, char const *argv[])
{
	int n, m, ta, tb, k;
	scanf("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
	}
	if(n <= k || m <= k) {
		printf("-1\n");
		exit(0);
	}

	a[0] = INT_MIN;
	int pt = 1;
	int ans = b[1];
	for(int i = 1; i <= k + 1; i++) {
		while(pt <= m && b[pt] < a[i] + ta) {
			++pt;
		}
		int rem = k - (i - 1);
		if(pt + rem > m) {
			printf("-1\n");
			exit(0);
		}
		ans = max(ans, b[pt + rem]);
	}
	printf("%d\n", ans + tb);
	return 0;
}