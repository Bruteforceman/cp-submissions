#include "bits/stdc++.h"
using namespace std;
int l[100010], r[100010];
long long w[100010]; 
vector <int> g[100010];
int start[100010], fin[100010];
int cur;
int ord[200010];
 
void dfs(int x, int par) {
	for(auto e : g[x]) {
		int i = l[e] ^ r[e] ^ x;
		if(e != par) {
			ord[++cur] = -e;
			start[e] = cur;
			dfs(i, e);
			ord[++cur] = e;
			fin[e] = cur;
		}
	}
}
 
long long t[200010 * 4];
long long sum[200010 * 4];
long long suf[200010 * 4];
long long pre[200010 * 4];
long long mn_pre[200010 * 4];
long long mx_suf[200010 * 4];
long long full[200010 * 4];
 
void build(int c = 1, int b = 1, int e = cur) {
	if(b == e) {
		long long val = (ord[b] < 0) ? -w[-ord[b]] : w[ord[b]];
		t[c] = max(0LL, val);
		full[c] = abs(val);
		sum[c] = val;
		suf[c] = pre[c] = full[c];
		mn_pre[c] = min(0LL, val);
		mx_suf[c] = max(0LL, val);
		return ;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	build(l, b, m);
	build(r, m + 1, e);
	sum[c] = sum[l] + sum[r];
	t[c] = max(t[l], t[r]);
	t[c] = max(t[c], suf[l] - mn_pre[r]);
	t[c] = max(t[c], mx_suf[l] + pre[r]);
	mx_suf[c] = max(mx_suf[r], sum[r] + mx_suf[l]);
	mn_pre[c] = min(mn_pre[l], sum[l] + mn_pre[r]);
	pre[c] = max(pre[l], sum[l] + pre[r]);
	pre[c] = max(pre[c], full[l] - mn_pre[r]);
	suf[c] = max(suf[r], suf[l] - sum[r]);
	suf[c] = max(suf[c], mx_suf[l] + full[r]);
	full[c] = max(full[l] - sum[r], sum[l] + full[r]);
}
 
void update(int x, int c = 1, int b = 1, int e = cur) {
	if(b == e) {
		long long val = (ord[b] < 0) ? -w[-ord[b]] : w[ord[b]];
		t[c] = max(0LL, val);
		full[c] = abs(val);
		sum[c] = val;
		suf[c] = pre[c] = full[c];
		mn_pre[c] = min(0LL, val);
		mx_suf[c] = max(0LL, val);
		return ;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	if(x <= m) update(x, l, b, m);
	else update(x, r, m + 1, e);
	sum[c] = sum[l] + sum[r];
	t[c] = max(t[l], t[r]);
	t[c] = max(t[c], suf[l] - mn_pre[r]);
	t[c] = max(t[c], mx_suf[l] + pre[r]);
	mx_suf[c] = max(mx_suf[r], sum[r] + mx_suf[l]);
	mn_pre[c] = min(mn_pre[l], sum[l] + mn_pre[r]);
	pre[c] = max(pre[l], sum[l] + pre[r]);
	pre[c] = max(pre[c], full[l] - mn_pre[r]);
	suf[c] = max(suf[r], suf[l] - sum[r]);
	suf[c] = max(suf[c], mx_suf[l] + full[r]);
	full[c] = max(full[l] - sum[r], sum[l] + full[r]);
}
 
int main(int argc, char const *argv[])
{
	int n, q;
	long long mxw;
	scanf("%d %d %lld", &n, &q, &mxw);
	for(int i = 1; i < n; i++) {
		scanf("%d %d %lld", &l[i], &r[i], &w[i]);
		g[l[i]].push_back(i);
		g[r[i]].push_back(i);
	}	
	dfs(1, 0);
	build();
	long long last = 0;
	for(int i = 1; i <= q; i++) {
		long long d, e;
		scanf("%lld %lld", &d, &e);
		d = (d + last) % (n - 1);
		e = (e + last) % mxw;
		d += 1;
		w[d] = e;
		update(start[d]);
		update(fin[d]);
		last = t[1];
		printf("%lld\n", last);
	}
	return 0;
}