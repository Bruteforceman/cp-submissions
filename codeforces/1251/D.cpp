#include "bits/stdc++.h"
using namespace std;
#define endl '\n'
typedef pair <int, int> pii;

int n;
long long s;
pii a[200010];
bool take[200010];

bool good(int x) {
	int cnt = n / 2;
	long long tot = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i].second < x) {
			tot += a[i].first;
			--cnt;
			take[i] = true;
		} else take[i] = false;
	}
	if(cnt < 0) return false;
	for(int i = 1; i <= n; i++) {
		if(cnt == 0) break;
		if(take[i]) continue;
		tot += a[i].first;
		--cnt;
		take[i] = true;
	}
	for(int i = 1; i <= n; i++) {
		if(!take[i]) {
			tot += max(x, a[i].first);
		}
	}
	return tot <= s;
}
int search(int b, int e) {
	if(b == e) return b;
	int m = (b + e + 1) >> 1;
	if(good(m)) return search(m, e);
	else return search(b, m - 1);
}
void solve() {
	scanf("%d %lld", &n, &s);	
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a + 1, a + n + 1);
	printf("%d\n", search(1, 1000000000));
}

int main(int argc, char const *argv[])
{
	// ios_base :: sync_with_stdio (false);
	// cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}