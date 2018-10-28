#include "bits/stdc++.h"
using namespace std;
int a[111];

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int mx = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	for(int i = mx; ; i++) {
		int x = 0;
		int y = 0;
		for(int j = 1; j <= n; j++) {
			x += a[j];
			y += i - a[j];
		}
		if(y > x) {
			printf("%d\n", i);
			exit(0);
		}
	}
	return 0;
}