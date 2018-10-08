#include "bits/stdc++.h"
using namespace std;
int n;
int m;
int l[100], r[100];
bool tmp[666];
int tot;

int query(vector <int> v) {
	++tot;
	assert(tot <= 20000);
	set <int> P (v.begin(), v.end());
	v = vector <int> (P.begin(), P.end());
	cout << "? " << v.size() << endl;
	for(auto i : v) {
		cout << i << " ";
	}
	cout << endl;
	int ans;
	cin >> ans;
	if(ans == -1) exit(0);
	return ans;
}

vector <int> c[2];
vector <int> can;
int edge;

void remove(int x) {
	can.erase(find(can.begin(), can.end(), x));
}

int search(int b, int e) {
	if(b == e) {
		return can[b];
	}
	int m = (b + e) >> 1;
	vector <int> p, q;
	for(auto i : c[0]) {
		p.push_back(i);
	}
	for(auto i : c[1]) {
		p.push_back(i);
	}
	for(int i = 0; i <= m; i++) {
		p.push_back(can[i]);
		q.push_back(can[i]);
	}
	if(query(p) > edge + query(q)) {
		return search(b, m);
	} else {
		return search(m + 1, e);
	}
}

int find(int b, int e, int node, int col) {
	if(b == e) {
		return c[col][b];
	}
	int m = (b + e) >> 1;
	vector <int> p;
	p.push_back(node);
	for(int i = 0; i <= m; i++) {
		p.push_back(c[col][i]);
	}
	if(query(p) > 0) {
		return find(b, m, node, col);
	} else {
		return find(m + 1, e, node, col);
	}
}

vector <int> g[666];
bool vis[666];
int anc[666];
vector <int> path;

void dfs(int x, int par) {
	vis[x] = true;
	for(auto i : g[x]) {
		if(i == par) continue;
		if(!vis[i]) {
			anc[i] = x;
			dfs(i, x);
		} else {
			int cur = x;
			while(cur != i) {
				path.push_back(cur);
				cur = anc[cur];
			}
			path.push_back(i);
			cout << "N " << path.size() << endl;
			for(auto i : path) {
				cout << i << " ";
			}
			cout << endl;
			exit(0);
		}
	}
}

void add() {
	int x = search(0, can.size() - 1);
	remove(x);
	vector <int> p = c[0];
	vector <int> q = c[1];
	p.push_back(x);
	q.push_back(x);

	int cnt = 0;
	bool white = false;
	bool black = false;

	int X = query(p);
	int Y = query(q);

	if(X > 0) {
		++cnt;
		int y = find(0, c[0].size() - 1, x, 0);
		// cout << x << " & " << y << endl;
		g[x].push_back(y);
		g[y].push_back(x);
		white = true;
	}
	if(Y > 0) {
		++cnt;
		int y = find(0, c[1].size() - 1, x, 1);
		// cout << x << " and " << y << endl;
		g[x].push_back(y);
		g[y].push_back(x);
		black = true;
	}
	edge += X + Y;
	assert(cnt);
	if(cnt == 2) {
		dfs(x, 0);
		exit(0);
	}
	if(white) {
		c[1].push_back(x);
	} else {
		c[0].push_back(x);
	}
}

int main(int argc, char const *argv[])
{
	cin >> n;
	c[0].push_back(1);
	for(int i = 2; i <= n; i++) {
		can.push_back(i);
	}
	for(int i = 2; i <= n; i++) {
		if(query({1, i})) {
			c[1].push_back(i);
			remove(i);
			g[i].push_back(1);
			g[1].push_back(i);
			break;
		}
	}
	edge = 1;
	while(!can.empty()) {
		add();
	}
	cout << "Y " << c[0].size() << endl;
	for(auto i : c[0]) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}