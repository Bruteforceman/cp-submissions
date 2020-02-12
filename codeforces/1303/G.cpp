#include <bits/stdc++.h>
using namespace std;
const int maxn = 150010;
vector <int> g[maxn];
int sub[maxn];
int a[maxn];
bool del[maxn];
long long res;
typedef long long ll;

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

        // **** May need long double typecasting here
        return (long double)(x->b - y->b)*(z->m - y->m) >= (long double)(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
		if(empty()) return is_query;
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
} H;

void subtree(int x, int par) 
{
	sub[x] = 1;
	for(auto i : g[x]) {
		if(i != par && !del[i]) {
			subtree(i, x);
			sub[x] += sub[i];
		}
	}
}
int centroid(int x, int par, int range) {
	for(auto i : g[x]) {
		if(i != par && !del[i] && sub[i] > range) {
			return centroid(i, x, range);
		}
	}
	return x;
}

int dep[maxn];
long long start[maxn], fin[maxn], sum[maxn];
void dfs(int x, int par) {
	fin[x] = sum[x] + fin[par];
	start[x] = start[par] + 1LL * dep[x] * a[x];
	res = max(res, fin[x]);
	res = max(res, start[x]);
	for(auto i : g[x]) {
		if(i != par && !del[i]) {
			dep[i] = 1 + dep[x];
			sum[i] = a[i] + sum[x];
			dfs(i, x);
		}
	}
}

vector <int> nodes;
void getNode(int x, int par) {
	nodes.push_back(x);
	for(auto i : g[x]) {
		if(i != par && !del[i]) {
			getNode(i, x);
		}
	}
}

void solve(int x) {
	subtree(x, 0);
	x = centroid(x, 0, sub[x] / 2);
	del[x] = true;
	dep[x] = 1; sum[x] = a[x];
	dfs(x, 0);
	// cout << "here " << x << endl;
	H.clear();
	for(auto i : g[x]) {
		if(del[i]) continue;
		nodes.clear();
		getNode(i, x);
		for(auto j : nodes) {
			res = max(res, start[j] + H.eval(sum[j] - a[x]) - sum[j]);
		}
		for(auto j : nodes) {
			H.insert_line(dep[j], fin[j]);
		}
	}
	H.clear();
	reverse(g[x].begin(), g[x].end());
	for(auto i : g[x]) {
		if(del[i]) continue;
		nodes.clear();
		getNode(i, x);
		for(auto j : nodes) {
			res = max(res, start[j] + H.eval(sum[j] - a[x]) - sum[j]);
		}
		for(auto j : nodes) {
			H.insert_line(dep[j], fin[j]);
		}
	}
	for(auto i : g[x]) {
		if(del[i]) continue;
		solve(i);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		g[p].push_back(q);
		g[q].push_back(p);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	solve(1);
	printf("%lld\n", res);
}