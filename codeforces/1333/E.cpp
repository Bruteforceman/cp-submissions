#include <bits/stdc++.h>
using namespace std;
int b[505][505];
function <bool (int, int, int, int)> rook, queen;
int vun(int a[3][3], function <bool(int, int, int, int)> reach) {
    bool vis[3][3];
    memset(vis, false, sizeof vis);
    int cur = 1;
    int cnt = 0;
    while(cur != INT_MAX) {
        int x = -1, y = -1;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(cur == a[i][j]) {
                    tie(x, y) = make_pair(i, j);
                    vis[x][y] = true;
                }
            }
        }
        int opt = INT_MAX;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(!vis[i][j] && reach(x, y, i, j)) {
                    opt = min(opt, a[i][j]);
                }
            }
        }
        if(opt == INT_MAX) for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(!vis[i][j]) {
                    opt = min(opt, a[i][j]);
                    ++cnt;
                }
            }
        }
        cur = opt;
    }
    return cnt;
}

int main() {
    rook = [&] (int i, int j, int x, int y) {
        return x == i || y == j;
    };
    queen = [&] (int i, int j, int x, int y) {
        return rook(i, j, x, y) || abs(x - i) == abs(y - j);
    };
    vector <int> v;
    for(int i = 1; i <= 9; i++) v.push_back(i);
    int a[3][3];
    do {
        int cur = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                a[i][j] = v[cur++];
            }
        }
        if(vun(a, rook) < vun(a, queen)) {
            break;
        }
    } while(next_permutation(v.begin(), v.end()));
    int n;
    cin >> n;
    if(n <= 2) {
        cout << -1 << endl;
        exit(0);
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            b[i][j] = a[i][j] + n*n - 9;
        }
    }
    int cur = 1;
    for(int i = 3; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(i & 1) b[j][i] = cur++;
            else b[i][j] = cur++;
        }
        for(int j = i - 1; j >= 0; j--) {
            if(i & 1) b[i][j] = cur++;
            else b[j][i] = cur++;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << b[i][j] << " \n"[j == n-1];
        }
    }
    return 0;
}
