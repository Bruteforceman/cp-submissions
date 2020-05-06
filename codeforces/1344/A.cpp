#include "bits/stdc++.h"
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];

void solve() {
	int n;
	scanf("%d", &n);
	set <int> s;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] = ((a[i] % n) + n) % n;
		s.insert((i + a[i]) % n);
	}
	if(s.size() == n) printf("YES\n");
	else printf("NO\n");
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