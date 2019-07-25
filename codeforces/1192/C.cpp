#include "bits/stdc++.h"
using namespace std;
int n;
string s[100010];
char txt[12];

const int mod = 998244353;
const int alpha = 62;

long long cnt[alpha][alpha];
long long ways[alpha][alpha][alpha];

inline int mapper(char x) {
	if(isalpha(x)) {
		if(islower(x)) {
			return x - 'a';
		} else return x - 'A' + 26;
	} else return x - '0' + 52;
}
bool palindrome(string &t) {
	int sz = t.size();
	for(int i = 0; i < sz; i++) {
		if(t[i] != t[sz - i - 1]) return false;
	}
	return true;
}

long long solve(int len) {
	memset(cnt, 0, sizeof cnt);
	set <string> st;

	for(int i = 1; i <= n; i++) {
		if(s[i].size() == len) {
			string r = s[i];
			reverse(r.begin(), r.end());
			if(st.find(r) != st.end()) continue;
			st.insert(s[i]);
			int x = mapper(s[i][0]);
			int y = mapper(s[i][len - 1]);
			if(!palindrome(s[i])) {
				cnt[x][y] += 1;
				cnt[y][x] += 1;
			} else {
				cnt[x][y] += 1;
			}
		}
	}
	for(int i = 0; i < alpha; i++) {
		for(int j = i; j < alpha; j++) {
			for(int k = j; k < alpha; k++) {
				ways[i][j][k] = 0;
				for(int l = 0; l < alpha; l++) {
					ways[i][j][k] += (((cnt[i][l] * cnt[j][l]) % mod) * cnt[k][l]) % mod;
				}
				ways[i][j][k] %= mod;
				ways[i][k][j] = ways[k][i][j] = ways[k][j][i] = ways[j][k][i] = ways[j][i][k] = ways[i][j][k];
			}
		}
	}

	int fac[5];
	fac[0] = 1;
	fac[1] = 1;
	fac[2] = 2;
	fac[3] = 6;
	fac[4] = 24;

	long long ans = 0;
	for(int i = 0; i < alpha; i++) {
		for(int j = i; j < alpha; j++) {
			for(int k = j; k < alpha; k++) {
				for(int l = k; l < alpha; l++) {
					long long arrange = 24;
					int arr[] = {i, j, k, l};
					int tot = 1;
					for(int x = 1; x < 4; x++) {
						if(arr[x] == arr[x - 1]) {
							++tot;
						} else {
							arrange /= fac[tot];
							tot = 1;
						}
					}
					arrange /= fac[tot];
					long long add = (ways[i][j][k] * ways[i][j][l]) % mod;
					add = (add * ways[i][k][l]) % mod;
					add = (add * ways[j][k][l]) % mod;
					ans += (add * arrange) % mod;
				}
			}
		}
	}
	return ans % mod;
}
int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%s", txt);
		s[i] = txt;
	}
	long long ans = 0;
	for(int i = 3; i <= 10; i++) {
		ans += solve(i);
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}