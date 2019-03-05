#include "bits/stdc++.h"
using namespace std;
int a[300010];

int main(int argc, char const *argv[])
{
	int n;
	long long sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	int m;
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		int q;
		scanf("%d", &q);
		printf("%lld\n", sum - a[n - q + 1]);
	}
	return 0;
}