#include "bits/stdc++.h"
using namespace std;
int n;
int a[400010];
int b[400010];

int solve(int bit) {
	for(int i = 0; i < n; i++) {
		b[i] = a[i] & ((1 << (bit + 1)) - 1);
	}
	sort(b, b + n);
	int cnt = 0;
	// x + y mod 2^(bit + 1) >= 2^bit
	// 2^bit <= x + y < 2^(bit + 1)
	// 2^(bit + 1) + 2^bit <= x + y <= 2^(bit + 2)
	for(int i = 0; i < n; i++) {
		cnt += upper_bound(b, b + i, (1 << (bit + 1)) - b[i] - 1) - lower_bound(b, b + i, (1 << bit) - b[i]);
		cnt += upper_bound(b, b + i, (1 << (bit + 2)) - b[i]) - lower_bound(b, b + i, (1 << (bit + 1)) + (1 << bit) - b[i]);
		cnt &= 1;
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	int ans = 0;
	for(int i = 0; i < 30; i++) {
		ans += solve(i) * (1 << i);
	}
	printf("%d\n", ans);
	return 0;
}