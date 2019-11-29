#include "bits/stdc++.h"
using namespace std;
int n;
int mx[4 * 1000010], mn[4 * 1000010], prop[4 * 1000010];
int a[1000010];

void pushdown(int c) {
	int l = c << 1;
	int r = l + 1;
	mx[l] += prop[c]; mn[l] += prop[c];
	mx[r] += prop[c]; mn[r] += prop[c];
	prop[l] += prop[c]; prop[r] += prop[c];
	prop[c] = 0;
}
void update(int x, int y, int val, int c = 1, int b = 1, int e = n) {
	if(x <= b && e <= y) {
		mx[c] += val;
		mn[c] += val;
		prop[c] += val;
		return ;
	}
	if(y < b || e < x) return ;
	pushdown(c);
	int l = c << 1;
	int r = l + 1;
	int m = (b + e) >> 1;
	update(x, y, val, l, b, m);
	update(x, y, val, r, m + 1, e);
	mx[c] = max(mx[l], mx[r]);
	mn[c] = min(mn[l], mn[r]);
}

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string s;
	cin >> s;
	int cur = 1, tot = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'L') {
			cur -= 1;
			cur = max(1, cur);
		} else if (s[i] == 'R') {
			cur += 1;
		} else {
			int val;
			if(s[i] == '(') val = 1;
			else if (s[i] == ')') val = -1;
			else val = 0;
			int add = val - a[cur];
			a[cur] = val;
			tot += add;
			update(cur, n, add);
		}
		if(mn[1] < 0 || tot != 0) printf("-1 ");
		else printf("%d ", mx[1]);
	}
	printf("\n");
	return 0;
}