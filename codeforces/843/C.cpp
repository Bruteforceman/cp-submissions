#include <bits/stdc++.h>
using namespace std;
#define move haha
const int maxn = 2e5 + 10;
vector <int> g[maxn];
int sub[maxn];
int dad[maxn];
vector <tuple <int, int, int>> move;

void dfs(int x, int par) {
    sub[x] = 1;
    for(auto i : g[x]) {
        if(i != par) {
            dfs(i, x);
            sub[x] += sub[i];
        }
    }
}
int centroid(int x, int par, int range) {
    for(int i : g[x]) {
        if(i != par && sub[i] > range) {
            return centroid(i, x, range);
        }
    }
    return x;
}
void makeChain(int x, int par, vector <int> &order) {
    dad[x] = par;
    for(auto i : g[x]) {
        if(i != par) {
            makeChain(i, x, order);
        }
    }
    order.push_back(x);
}
void process(int i, int root) {
    vector <int> order;
    makeChain(i, root, order);
    move.emplace_back(root, i, order[0]);
    for(int i = 1; i < order.size(); i++) {
        move.emplace_back(order[i - 1], dad[order[i - 1]], order[i]);
    }
    if(order.size() <= 2) return ;
    order.insert(order.begin(), root);
    int piv = *(order.end() - 2);
    for(int i = order.size() - 4; i >= 0; i--) {
        move.emplace_back(order[i], order[i + 1], piv);
    }
}
int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int p, q;
        cin >> p >> q;
        g[p].push_back(q);
        g[q].push_back(p);
    }
    dfs(1, 0);
    int root = centroid(1, 0, sub[1] / 2);
    dfs(root, 0);
    for(int i : g[root]) {
        if(sub[i] * 2 < sub[root]) {
            process(i, root);
        } else {
            for(int j : g[i]) {
                if(j != root) process(j, i);
            }
        }
    }
    cout << move.size() << endl;
    for(auto i : move) {
        int p, q, r;
        tie(p, q, r) = i;
        cout << p << ' ' << q << ' ' << r << endl;
    }
    return 0;
}
