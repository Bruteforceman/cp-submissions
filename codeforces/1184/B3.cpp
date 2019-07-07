#include "bits/stdc++.h"
using namespace std;
int adj[111][111];
int xp[100010], a[100010], f[100010], p[100010];
int xb[100010], d[100010], g[100010];

const long long inf = 1e17;
long long opt[111];
long long profit[100010];
const long long max_profit = 1000000000;

struct MaxFlow {
	#define int long long
	#define MAX_N 100010
	#define INF inf
	typedef long long lld;

	struct Node
	{
	    vector<int> adj;
	};
	Node graf[MAX_N];

	struct Edge
	{
	    int u, v, cap;
	    int flow;
	};
	vector<Edge> E;

	int v;
	int s, t;
	int dist[MAX_N];
	int upTo[MAX_N];

	int idd = 0;

	//Dinicov algoritam za nalazenje maksimalnog protoka izmedju dva cvora u grafu
	//Slozenost: O(V^2 * E)

	inline bool BFS()
	{
	    for (int i=1;i<=v;i++) dist[i] = -1;
	    queue<int> bfs_queue;
	    bfs_queue.push(s);
	    dist[s] = 0;
	    while (!bfs_queue.empty())
	    {
	        int xt = bfs_queue.front();
	        bfs_queue.pop();
	        for (int i=0;i<graf[xt].adj.size();i++)
	        {
	            int currID = graf[xt].adj[i];
	            int xt1 = E[currID].v;
	            if (dist[xt1] == -1 && E[currID].flow < E[currID].cap)
	            {
	                bfs_queue.push(xt1);
	                dist[xt1] = dist[xt] + 1;
	            }
	        }
	    }
	    return (dist[t] != -1);
	}

	inline int DFS(int xt, int minCap)
	{
	    if (minCap == 0) return 0;
	    if (xt == t) return minCap;
	    while (upTo[xt] < graf[xt].adj.size())
	    {
	        int currID = graf[xt].adj[upTo[xt]];
	        int xt1 = E[currID].v;
	        if (dist[xt1] != dist[xt] + 1)
	        {
	            upTo[xt]++;
	            continue;
	        }
	        int aug = DFS(xt1, min(minCap, E[currID].cap - E[currID].flow));
	        if (aug > 0)
	        {
	            E[currID].flow += aug;
	            if (currID&1) currID--; else currID++;
	            E[currID].flow -= aug;
	            return aug;
	        }
	        upTo[xt]++;
	    }
	    return 0;
	}
	inline int Dinic()
	{
	    int flow = 0;
	    while (true)
	    {
	        if (!BFS()) break;
	        for (int i=1;i<=v;i++) upTo[i] = 0;
	        while (true)
	        {
	            int currFlow = DFS(s, INF);
	            if (currFlow == 0) break;
	            flow += currFlow;
	        }
	    }
	    return flow;
	}
	inline void addEdge(int u, int v, int cap)
	{
		// cout << u << ' ' << v << ' ' << cap << endl;
	    Edge E1, E2;
	    
	    E1.u = u, E1.v = v, E1.cap = cap, E1.flow = 0;
	    E2.u = v, E2.v = u, E2.cap = 0, E2.flow = 0;
	    
	    graf[u].adj.push_back(idd++);
	    E.push_back(E1);
	    graf[v].adj.push_back(idd++);
	    E.push_back(E2);
	}
	#undef int
} F;

bool bad[100010];
vector <int> forb[100010];
void prop(int x) {
	bad[x] = true; 
	for(auto i : forb[x]) {
		if(!bad[i]) {
			prop(i);
		}
	}	
}

int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i != j) {
				adj[i][j] = 1000000001;
			}
		}
		opt[i] = -inf;
	}
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = adj[v][u] = 1;
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	int s, b, k;
	cin >> s >> b >> k;

	vector <pair <int, int>> v;

	for(int i = 1; i <= s; i++) {
		cin >> xp[i] >> a[i] >> f[i] >> p[i];
		v.emplace_back(a[i], i);
	}
	for(int i = 1; i <= b; i++) {
		cin >> xb[i] >> d[i] >> g[i];
		v.emplace_back(d[i], -i);
	}
	sort(v.begin(), v.end());
	for(auto i : v) {
		int id = abs(i.second);
		if(i.second > 0) {
			int x = xp[id];
			profit[id] = -inf;
			for(int j = 1; j <= n; j++) {
				if(adj[x][j] <= f[id]) {
					profit[id] = max(profit[id], opt[j] - p[id]);
				}
			}
		} else {
			int x = xb[id];
			opt[x] = max(opt[x], (long long) g[id]);
		}
	}
	for(int i = 1; i <= k; i++) {
		int u, v;
		cin >> u >> v;
		forb[v].push_back(u);
	}
	for(int i = 1; i <= s; i++) {
		if(!bad[i] && profit[i] < -max_profit) {
			prop(i);
		}
	}
	F.s = s + 1;
	F.t = s + 2;
	F.v = s + 2;
	for(int i = 1; i <= s; i++) {
		if(bad[i]) continue;
		for(auto j : forb[i]) {
			if(!bad[j]) {
				F.addEdge(j, i, inf);
			}
		}
	}
	long long sum = 0;
	for(int i = 1; i <= s; i++) {
		if(!bad[i]) {
			if(profit[i] > 0) {
				F.addEdge(F.s, i, profit[i]);
				sum += profit[i];
			} else {
				F.addEdge(i, F.t, -profit[i]);
			}
		}
	}
	cout << sum - F.Dinic() << endl;
	return 0;
}