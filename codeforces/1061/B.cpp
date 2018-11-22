#include "bits/stdc++.h"
using namespace std;
int a[100010];

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);

	long long sum = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);

	long long take = 0;
	int last = 0;
	for(int i = 1; i <= n; i++) {
		if(i > 1) a[i] = min(last - 1, a[i]);
		a[i] = max(a[i], 1);
		last = min(a[i], a[i + 1] + 1);
		take += a[i] - last + 1; 
	}
	printf("%lld\n", sum - take);
	return 0;
}