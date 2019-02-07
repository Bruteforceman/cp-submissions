#include "bits/stdc++.h"
using namespace std;
int n, m, k;
int a[100010];

int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &n, &m, &k);
	vector <int> v;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 2; i <= n; i++) {
		v.emplace_back(a[i] - a[i-1]);
	}
	sort(v.begin(), v.end());
	int ans = a[n] - a[1] + 1;
	for(int i = 2; i <= k; i++) {
		ans -= v.back() - 1;
		v.pop_back();
	}
	printf("%d\n", ans);
	return 0;
}