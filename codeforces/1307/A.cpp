#include "bits/stdc++.h"
using namespace std;
int a[111];
void solve() {
	int n, d;
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	for(int i = 1; i < n; i++) {
		while(a[i] > 0 && d >= i) {
			a[0] += 1;
			a[i] -= 1;
			d -= i;
		}
	}
	printf("%d\n", a[0]);
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