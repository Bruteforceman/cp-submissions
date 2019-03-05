#include "bits/stdc++.h"
using namespace std;
string s;
int n;
int mem[555][555];

int dp(int l, int r) {
	if(l > r) return 0;
	int &ans = mem[l][r];
	if(ans != -1) return ans;
	ans = n;
	for(int i = l; i <= r; i++) {
		if(s[i] == s[l - 1] || s[i] == s[r + 1]) {
			ans = min(ans, dp(l, i - 1) + dp(i + 1, r));
		} else {
			ans = min(ans, dp(l, i - 1) + dp(i + 1, r) + 1);
		}
	} 
	return ans;
}

int main(int argc, char const *argv[])
{
	memset(mem, -1, sizeof mem);
	cin >> n >> s;
	s = "&" + s + "&";
	printf("%d\n", dp(1, n));
	return 0;
}