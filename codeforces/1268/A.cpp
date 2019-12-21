#include "bits/stdc++.h"
using namespace std;
int a[200010];
int b[200010];

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	bool bad = false;
	for(int i = 1; i <= n; i++) {
		a[i] = s[i - 1] - '0';
	}
	string t;
	for(int i = 0; i < n; i++) {
		t += s[i % k];
	}
	if(t >= s) {
		cout << t.size() << endl;
		cout << t << endl;
		exit(0);
	}
	int carry = 1;
	for(int i = k; i >= 0; i--) {
		a[i] += carry;
		if(a[i] == 10) {
			a[i] = 0;
			carry = 1;
		} else carry = 0;
	}
	int start;
	if(a[0] > 0) start = 0;
	else start = 1;
	for(int i = start; i < start + k; i++) {
		int cur = i;
		while(cur <= n) {
			b[cur] = a[i];
			cur += k;
		}
	}
	cout << (n - start + 1) << endl;
	for(int i = start; i <= n; i++) {
		cout << b[i];
	}
	cout << endl;
	return 0;
}