#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
int ans[100010];
int aux[100010];
int dp[100010];
int type[100010];

string query(vector <pii> &v) {
    if(v.size() == 0) return "";
    cout << "Q ";
    cout << v.size();
    for(int i = 0; i < v.size(); i++) {
        cout << " " << v[i].first << " " << v[i].second;
    }
    cout << endl;
    string s = "";
    cin >> s;
    v.clear();
    return s;
}

void solve() {
    int n;
    cin >> n;

    vector <pii> v;
    for(int i = 2; i <= n; i += 2) {
        v.push_back(pii(i - 1, i));
    }
    string s = query(v);
    for(int i = 2; i <= n; i += 2) {
        ans[i] = s[(i - 2) / 2] - '0';
    }
    for(int i = 3; i <= n; i += 2) {
        v.push_back(pii(i - 1, i));
    }
    s = query(v);
    for(int i = 3; i <= n; i += 2) {
        ans[i] = s[(i - 3) / 2] - '0';
    }

    vector <int> can;
    for(int i = 1; i <= n; i++) {
        if(!ans[i]) {
            can.push_back(i);
        }
    }

    for(int i = 2; i <= 4; i++) {
        for(int x = i; x < can.size(); x += 3) {
            v.push_back(pii(can[x - 2], can[x]));
        }
        s = query(v);
        for(int x = i; x < can.size(); x += 3) {
            aux[can[x]] = s[(x - i) / 3] - '0';
        }
    }
    for(int i = 0; i < can.size(); i++) {
        if(i < 2) {
            dp[can[i]] = i + 1;
        } else {
            if(aux[can[i]] == 1) {
                dp[can[i]] = dp[can[i - 2]];
            } else {
                dp[can[i]] = 6 - dp[can[i - 1]] - dp[can[i - 2]];
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(ans[i] == 1) {
            dp[i] = dp[i - 1];
        }
    }
    vector <int> col[4];
    for(int i = 1; i <= n; i++) {
        col[dp[i]].push_back(i);
    }
    cout << "A " << col[1].size() << " " << col[2].size() << " " << col[3].size() << endl;
    for(int i = 1; i <= 3; i++) {
        for(int j : col[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
