#include "bits/stdc++.h"
using namespace std;
int a[100010], b[100010], mx[100010], mn[100010];

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
		}
		mx[0] = -1;
		mn[0] = 1;
		for(int i = 1; i <= n; i++) {
			mx[i] = max(mx[i - 1], a[i]);
			mn[i] = min(mn[i - 1], a[i]);
		}
		bool good = true;
		for(int i = n; i >= 1; i--) {
			if(a[i] < b[i] && mx[i - 1] != 1) {
				good = false;
			}
			if(a[i] > b[i] && mn[i - 1] != -1) {
				good = false;
			}
		}
		if(good) {
			printf("YES\n");
		} else printf("NO\n");
	}
	return 0;
}