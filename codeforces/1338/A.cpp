#include "bits/stdc++.h"
using namespace std;
int a[100010];

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	for(int x = 1; x <= t; x++) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		int opt = a[0];
		int ans = 0;
		for(int i = 1; i < n; i++) {
			if(opt > a[i]) {
				ans = max(ans, __lg(opt - a[i]) + 1);
			}
			opt = max(opt, a[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}