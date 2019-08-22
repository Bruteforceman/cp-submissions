#include "bits/stdc++.h"
using namespace std;
int nxt[26][400010];
int link[400010];
int node;
const int alpha = 26;
int par[400010];
char let[400010];
vector <int> g[400010], v[400010], cont[400010];
int endp[400010];
int trans[400010];
int ans[400010];

int insert_aho(string s) {
	int cur = 0;
	for(int i = 0; i < s.size(); i++) {
		int c = s[i] - 'a';
		if(nxt[c][cur] == -1) {
			nxt[c][cur] = ++node;
		}
		cur = nxt[c][cur];
	}
	return cur;
}
void build_aho() {
	queue <int> q;
	q.push(0);
	link[0] = 0;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int i = 0; i < alpha; i++) {
			if(nxt[i][x] == -1) continue;
			int cur = link[x];
			int y = nxt[i][x];
			while(cur > 0 && nxt[i][cur] == -1) {
				cur = link[cur];
			}
			if(nxt[i][cur] != -1 && nxt[i][cur] != y) {
				cur = nxt[i][cur];
			}
			link[y] = cur;
			q.push(y);
		}
	}
}
int add_char(int cur, int c) {
	while(cur > 0 && nxt[c][cur] == -1) {
		cur = link[cur];
	}
	if(nxt[c][cur] != -1) {
		cur = nxt[c][cur];
	}
	return cur;
}

int in[400010], out[400010];
int moment;
int t[400010];

void dfs(int x) {
	in[x] = ++moment;
	for(auto i : g[x]) {
		dfs(i);
	}
	out[x] = moment;
}
void update(int x, int val) {
	for(int i = x; i <= moment; i += i & (-i)) {
		t[i] += val;
	}
}
int query(int x) {
	int sum = 0;
	for(int i = x; i > 0; i -= i & (-i)) {
		sum += t[i];	
	}
	return sum;
}

void solve(int x) {
	if(x > 0) {
		update(in[trans[x]], 1);
	}
	for(auto i : cont[x]) {
		int p = endp[i];
		ans[i] = query(out[p]) - query(in[p] - 1);
	}
	for(auto i : v[x]) {
		solve(i);
	}
	if(x > 0) {
		update(in[trans[x]], -1);
	}
}

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	memset(nxt, -1, sizeof nxt);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		par[i] = 0;
		if(c == 2) {
			cin >> par[i] >> let[i];
		} else {
			cin >> let[i];
		}
		v[par[i]].push_back(i);
	}
	int m;
	cin >> m;
	for(int i = 1; i <= m; i++) {
		string s;
		int id;
		cin >> id >> s;
		endp[i] = insert_aho(s);
		cont[id].push_back(i);
	}
	build_aho();
	for(int i = 1; i <= node; i++) {
		g[link[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++) {
		if(par[i] == 0) {
			trans[i] = add_char(0, let[i] - 'a'); 
		} else {
			trans[i] = add_char(trans[par[i]], let[i] - 'a');
		}
	}
	dfs(0);
	solve(0);
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}