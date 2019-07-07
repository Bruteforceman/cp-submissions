#include "bits/stdc++.h"
using namespace std;
int adj[111][111];
int xp[100010], a[100010], f[100010], p[100010];
int xb[100010], d[100010], g[100010];
const int inf = 1e8;

struct MaxFlow {
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
} F;


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

	int s, b, k, h;
	cin >> s >> b >> k >> h;

	vector <pair <int, int>> v;

	for(int i = 1; i <= s; i++) {
		cin >> xp[i] >> a[i] >> f[i];
	}
	for(int i = 1; i <= b; i++) {
		cin >> xb[i] >> d[i];
	}
	F.s = s + b + 1;
	F.t = s + b + 2;
	F.v = s + b + 2;
	for(int i = 1; i <= s; i++) {
		for(int j = 1; j <= b; j++) {
			if(a[i] >= d[j] && adj[xp[i]][xb[j]] <= f[i]) {
				F.addEdge(i, s + j, 1);
			}
		}
	}
	for(int i = 1; i <= s; i++) {
		F.addEdge(F.s, i, 1);
	}
	for(int i = 1; i <= b; i++) {
		F.addEdge(s + i, F.t, 1);
	}
	int mat = F.Dinic();
	cout << min(1LL * mat * k, 1LL * h * s) << endl;
	return 0;
}