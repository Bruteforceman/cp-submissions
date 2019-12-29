#include "bits/stdc++.h"
using namespace std;
int a[200010];
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
		bool found = false;
		for(int i = 2; i <= n; i++) {
			if(abs(a[i] - a[i - 1]) > 1) {
				printf("YES\n");
				printf("%d %d\n", i - 1, i);
				found = true;
				break;
			}
		}
		if(!found) printf("NO\n");
	}
	return 0;
}