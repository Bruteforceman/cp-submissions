#include "bits/stdc++.h"
using namespace std;

int ceiling(int x, int y) {
	return (x + y - 1) / y;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, x, y, d;
		scanf("%d %d %d %d", &n, &x, &y, &d);
		int ans = INT_MAX;
		if(abs(x - y) % d == 0) {
			ans = min(ans, abs(x - y) / d);
		}
		if(abs(1 - y) % d == 0) {
			ans = min(ans, (abs(1 - y) / d) + ceiling(abs(x - 1), d));
		} 
		if(abs(n - y) % d == 0) {
			ans = min(ans, (abs(n - y) / d) + ceiling(abs(n - x), d));
		}
		if(ans == INT_MAX) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}