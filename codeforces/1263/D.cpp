#include "bits/stdc++.h"
using namespace std;
vector <int> g[300010];
bool vis[300010];
void add(int x, int y) {
	g[x].push_back(y);
	g[y].push_back(x);
}
void dfs(int x) {
	vis[x] = true;
	for(auto i : g[x]) {
		if(!vis[i]) {
			dfs(i);
		}
	}
}
int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < s.size(); j++) {
			add(s[j] - 'a', 26 + i);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(!vis[26 + i]) {
			dfs(26 + i);
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}