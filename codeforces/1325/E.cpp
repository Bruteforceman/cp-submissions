#include "bits/stdc++.h"
using namespace std;

vector <int> g[1000010];
vector <int> l, r;
const int inf = 1e9;
set <pair <int,int>> cont;
int dist[1000010], from[1000010];

bool addEdge(int p, int q) {
	if(p > q) swap(p, q);
	// cout << p << ' ' << q << endl;
	l.push_back(p);
	r.push_back(q);
	g[p].push_back(q);
	g[q].push_back(p);
	if(cont.find(make_pair(p, q)) != cont.end()) return true;
	cont.insert(make_pair(p, q));
	return false;
}

int solve(int u) {
	queue <int> Q;
	for(int i = 0; i < l.size(); i++) {
		dist[l[i]] = dist[r[i]] = -1;
		from[l[i]] = from[r[i]] = 0;
	}
	for(auto i : g[u]) {
		dist[i] = 1;
		from[i] = i;
		Q.push(i);
	}
	while(!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for(auto i : g[v]) {
			if(i == u) continue;
			if(dist[i] == -1) {
				dist[i] = 1 + dist[v];
				from[i] = from[v];
				Q.push(i);
			}
		}
	}
	int ans = inf;
	for(int i = 0; i < l.size(); i++) {
		if(from[l[i]] != from[r[i]] && dist[l[i]] != -1 && dist[r[i]] != -1) {
			ans = min(ans, dist[l[i]] + dist[r[i]] + 1);
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	bool dup = false;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		vector <int> v;
		for(int j = 2; j <= 1000; j++) {
			int cnt = 0;
			while(x % j == 0) {
				x /= j;
				++cnt;
			}
			if(cnt & 1) {
				v.push_back(j);
			}
		}
		if(x > 1) v.push_back(x);
		if(v.size() == 2) {
			dup |= addEdge(v[0], v[1]);
		} else if (v.size() == 1) {
			dup |= addEdge(0, v[0]);
		} else {
			printf("1\n");
			exit(0);
		}
	}
	if(dup) {
		printf("2\n");
		exit(0);
	}
	int ans = inf;
	for(int i = 0; i <= 1000; i++) {
		ans = min(ans, solve(i));
	}
	if(ans > n) ans = -1;
	printf("%d\n", ans);
	return 0;
}