#include "bits/stdc++.h"
using namespace std;
int a[100010];
void solve() {
	int n, x;
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	int mx = *max_element(a, a + n);
	if(mx <= x) printf("%d\n", (x + mx - 1) / mx);
	else printf("%d\n", count(a, a + n, x) ? 1 : 2);
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}
 	return 0; 
}