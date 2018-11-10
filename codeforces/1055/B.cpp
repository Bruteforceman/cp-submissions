#include "bits/stdc++.h"
using namespace std;
long long a[100010];
int good[100010];

int main(int argc, char const *argv[])
{
	int n, m, l;
	scanf("%d %d %d", &n, &m, &l);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	int seg = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > l) {
			good[i] = 1;
			if(good[i - 1] == 0) ++seg;
		}
	}
	for(int i = 1; i <= m; i++) {
		int c, d;
		scanf("%d", &c);
		if(c == 0) {
			printf("%d\n", seg);
		} else {
			scanf("%d %d", &c, &d);
			a[c] += d;
			if(good[c] == 0 && a[c] > l) {
				good[c] = 1;
				int cnt = good[c - 1] + good[c + 1];
				if(cnt == 0) ++seg;
				else if (cnt == 2) --seg;
			}
		}
	}
	return 0;
}