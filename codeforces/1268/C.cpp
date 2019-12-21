#include "bits/stdc++.h"
using namespace std;
int t[200010];
int a[200010];
int n;
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
	return query(y) - query(x - 1);
}

long long inv[200010], comb[200010];
int pos[200010];

long long nat_sum(int x) {
	return (1LL * (x + 1) * x) / 2;
}

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		inv[i] = inv[i - 1] + query(pos[i], n);
		update(pos[i], 1);
	}

	set <int> first, last;
	long long sumf = 0, suml = 0;
	for(int i = 1; i <= n; i++) {
		if(first.empty() || pos[i] < *first.rbegin()) {
			first.insert(pos[i]);
			sumf += pos[i];
		} else {
			last.insert(pos[i]);
			suml += pos[i];
		}
		while(first.size() > last.size() + 1) {
			int val = *first.rbegin();
			first.erase(val);
			sumf -= val;
			last.insert(val);
			suml += val;
		}
		while(first.size() < last.size()) {
			int val = *last.begin();
			last.erase(val);
			suml -= val;
			first.insert(val);
			sumf += val;
		}
		int med = *first.rbegin();
		comb[i] += (1LL * first.size() * med - sumf);
		comb[i] += (suml - 1LL * last.size() * med);
		if(i % 2 == 1) {
			comb[i] -= nat_sum(i / 2) * 2;
		} else {
			comb[i] -= nat_sum((i / 2) - 1) + nat_sum(i / 2);
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << (inv[i] + comb[i]) << ' ';
	}
	cout << endl;
	return 0;
}