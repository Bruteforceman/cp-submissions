#include "bits/stdc++.h"
using namespace std;
int n;
int a[300010], b[300010];
typedef pair <int, int> pii;
int t[4 * 300010];
const int inf = 1e9;

void update(int x, int val, int c = 1, int b = 0, int e = n) {
	if(b == e) {
		t[c] = val;
		return ;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	if(x <= m) {
		update(x, val, l, b, m);
	} else {
		update(x, val, r, m + 1, e);
	}
	t[c] = max(t[l], t[r]);
}

int search(int val, int c = 1, int b = 0, int e = n) {
	if(b == e) {
		return b;
	}
	int m = (b + e) >> 1;
	int l = c << 1;
	int r = l + 1;
	if(t[l] > val) return search(val, l, b, m); 
	else return search(val, r, m + 1, e);
}

vector <int> solve() {
	vector <pii> v;
	map <pii, int> idx;
	for(int i = 1; i <= n; i++) {
		if(a[i] > b[i]) {
			v.push_back(pii(b[i], a[i]));
			idx[pii(b[i], a[i])] = i;
		}
	}
	sort(v.begin(), v.end());
	for(int i = 0; i <= n; i++) {
		update(i, -inf);
	}
	for(int i = 0; i < v.size(); i++) {
		update(i, v[i].second);
	}
	int prev = 0;
	vector <int> ret;
	while(t[1] > prev) {
		int id = search(prev);
		prev = v[id].first;
		update(id, -inf);
		ret.push_back(idx[v[id]]);
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	vector <int> p = solve();
	for(int i = 1; i <= n; i++) {
		a[i] = 2*n - a[i] + 1;
		b[i] = 2*n - b[i] + 1;
	}
	vector <int> q = solve();
	if(p.size() < q.size()) swap(p, q);

	printf("%d\n", (int) p.size());
	for(auto i : p) {
		printf("%d ", i);
	} 
	printf("\n");
	return 0;
}