#include "bits/stdc++.h"
using namespace std;
int a[100010], b[100010];
int cnt[2];
int dnt[2];

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie (0);

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i] & 1] += 1;
	}
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		dnt[b[i] & 1] += 1;
	}
	cout << (min(cnt[0], dnt[1]) + min(cnt[1], dnt[0])) << endl;
	return 0;
}