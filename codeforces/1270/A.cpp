#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k1, k2;
		scanf("%d %d %d", &n, &k1, &k2);
		bool first = false;
		for(int i = 1; i <= k1; i++) {
			int x;
			scanf("%d", &x);
			if(x == n) first = true;
		}
		for(int i = 1; i <= k2; i++) {
			int x;
			scanf("%d", &x);
		}
		if(first) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}