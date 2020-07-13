#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 3e2 + 10;
int l[maxm], r[maxm];
int a[maxn];
int maxVal[maxn], minVal[maxn];
int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
    }
    vector <pair <int, int>> range;
    range.emplace_back(1, 0);
    range.emplace_back(n, 1);
    for(int i = 1; i <= m; i++) {
       int p = l[i], q = r[i];
       if(p > 1) range.emplace_back(p - 1, 1);
       range.emplace_back(p, 0);
       range.emplace_back(q, 1);
       if(q < n) range.emplace_back(q + 1, 0);
    }
    sort(range.begin(), range.end());
    range.erase(unique(range.begin(), range.end()), range.end());
    vector <pair <int, int>> v;
    for(int i = 0; i < range.size(); i += 2) {
        int p = range[i].first;
        int q = range[i + 1].first;
        maxVal[v.size()] = INT_MIN;
        minVal[v.size()] = INT_MAX;
        for(int j = p; j <= q; j++) {
            maxVal[v.size()] = max(maxVal[v.size()], a[j]);
            minVal[v.size()] = min(minVal[v.size()], a[j]);
        }
        v.emplace_back(p, q);
    }
    int ans = 0;
    vector <int> res;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            int diff = maxVal[j] - minVal[i];
            vector <int> sols;
            for(int k = 1; k <= m; k++) {
                if(l[k] <= v[i].first && v[i].second <= r[k]) {
                    if(r[k] < v[j].first || v[j].second < l[k]) {
                        ++diff;
                        sols.push_back(k);
                    }
                }
            }
            if(ans < diff) {
                ans = diff;
                res = sols;
            }
        }
    }
    cout << ans << endl;
    cout << res.size() << endl;
    for(int i : res) cout << i << ' ';
    cout << endl;
    return 0;
}
