#include "bits/stdc++.h"
using namespace std;
set <int> ls[3];
int n;
char s[200010];

struct tree {
	int t[200010];
	tree () {
		memset(t, 0, sizeof t);
	}
	void update(int x, int val) {
		for(int i = x; i <= n; i += i & (-i)) {
			t[i] += val;
		}
	}
	int query(int x) {
		int ans = 0;
		for(int i = x; i > 0; i -= i & (-i)) {
			ans += t[i];
		}
		return ans;
	}
	int query(int x, int y) {
		if(x > y) return 0;
		return query(y) - query(x-1);
	}
} T[3];

int id(int x) {
	return (3 + (x % 3)) % 3;
}
int idx(char c) {
	if(c == 'P') return 0;
	if(c == 'R') return 1;
	return 2;
}

int Count(int x) {
	int tot = T[x].query(1, n);
	int nxt = id(x + 1);
	int prv = id(x - 1);
	if(ls[prv].size() == 0) return tot;
	if(ls[nxt].size() == 0) return 0;

	int ln = *ls[nxt].begin();
	int lp = *ls[prv].begin();
	tot -= T[x].query(lp, ln);

	int rn = *ls[nxt].rbegin();
	int rp = *ls[prv].rbegin();

	tot -= T[x].query(rn, rp);

	return tot;
}

void update(int pos, char c) {
	int x = idx(c);
	int y = idx(s[pos]);
	ls[y].erase(pos);
	ls[x].insert(pos);
	T[y].update(pos, -1);
	T[x].update(pos, 1);
	s[pos] = c;
}

int main(int argc, char const *argv[])
{
	int Q;
	scanf("%d %d", &n, &Q);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) {
		ls[idx(s[i])].insert(i);
		T[idx(s[i])].update(i, 1);
	}
	printf("%d\n", Count(0) + Count(1) + Count(2));
	while(Q--) {
		int pos;
		char c;
		scanf("%d %c", &pos, &c);
		update(pos, c);
		printf("%d\n", Count(0) + Count(1) + Count(2));
	}
	return 0;
}