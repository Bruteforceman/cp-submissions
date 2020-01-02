#include "bits/stdc++.h"
using namespace std;
int p[200010];
int nxt[200010];
const int magic = 107;

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	s = "$" + s;
	for(int i = 1; i <= n; i++) {
		p[i] = p[i - 1] + (s[i] == '1');
	}
	nxt[n + 1] = n + 1;
	for(int i = n; i >= 1; i--) {
		nxt[i] = nxt[i + 1];
		if(s[i] == '1') nxt[i] = i;
	}
	long long ans = 0;
	for(int k = 1; k <= magic; k++) {
		map <int, int> mp;
		mp[0] += 1;
		for(int i = 1; i <= n; i++) {
			ans += mp[i - k * p[i]];
			mp[i - k * p[i]] += 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		int cur = i;
		int tmp;
		while(cnt * magic <= n) {
			cur = nxt[cur];
			if(cur > n) break;
			cnt += 1;
			tmp = nxt[cur + 1] - 1;
			int start = max(magic, ((cur - i + 1) / cnt));
			int end = (tmp - i + 1) / cnt;
			ans += max(0, end - start);
			if((cur - i + 1) % cnt == 0 && (cur - i + 1) / cnt > magic) {
				++ans;
			}
			cur += 1;
		}
	}
	cout << ans << endl;
	return 0;
}