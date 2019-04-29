#include "bits/stdc++.h"
using namespace std;
int a[200010];
int n;

int sum[200010 * 4];
int opt[200010 * 4];

int mxp[200010 * 4];
int mxs[200010 * 4];
int mns[200010 * 4];
int mnp[200010 * 4];

int pre[200010 * 4], suf[200010 * 4];

void update(int x, int val, int c = 1, int b = 1, int e = n) {
	if(b == e) {
		sum[c] = val;
		pre[c] = suf[c] = opt[c] = abs(val); 
		mxp[c] = mxs[c] = max(0, val);
		mnp[c] = mns[c] = min(0, val);
		return ;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	if(x <= m) update(x, val, l, b, m);
	else update(x, val, r, m + 1, e);
	sum[c] = sum[l] + sum[r];
	suf[c] = max(suf[r], suf[l] + sum[r]);
	suf[c] = max(suf[c], -mns[l] + (sum[r] - 2 * mnp[r]));
	pre[c] = max(pre[l], -sum[l] + pre[r]);
	pre[c] = max(pre[c], (sum[l] - 2 * mnp[l]) + mxp[r]);

	mxp[c] = max(mxp[l], sum[l] + mxp[r]);
	// mxs[c] = max(mxs[r], sum[r] + mxs[r]);
	mns[c] = min(mns[r], sum[r] + mns[l]);
	mnp[c] = min(mnp[l], sum[l] + mnp[r]);

	opt[c] = max(opt[l], opt[r]);
	opt[c] = max(opt[c], suf[l] + mxp[r]);
	opt[c] = max(opt[c], -mns[l] + pre[r]);
}


char txt[200010];

int main(int argc, char const *argv[])
{
	int q;
	scanf("%d %d", &n, &q);
	n = 2 * (n - 1);
	scanf("%s", txt);

	for(int i = 1; i <= n; i++) {
		a[i] = (txt[i - 1] == '(') ? 1 : -1;
		update(i, a[i]);
	}

	printf("%d\n", opt[1]);
	while(q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		swap(a[x], a[y]);
		update(x, a[x]);
		update(y, a[y]);
		printf("%d\n", opt[1]);
	}
	return 0;
}