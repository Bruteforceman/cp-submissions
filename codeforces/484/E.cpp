#include <bits/stdc++.h>
using namespace std;
int t[100010 * 4];
int lt[100010 * 4];
int rt[100010 * 4];
int n;
#define update wsdfdf
void update(int x, int val, int c = 1, int b = 1, int e = n) {
    if(b == e) {
        t[c] = lt[c] = rt[c] = val;
        return ;
    }
    int m = (b + e) >> 1;
    int l = c << 1;
    int r = l + 1;
    if(x <= m) update(x, val, l, b, m);
    else update(x, val, r, m+1, e);
    t[c] = max(t[l], t[r]);
    t[c] = max(t[c], rt[l] + lt[r]);    
    if(t[l] == (m - b + 1)) lt[c] = t[l] + lt[r];
    else lt[c] = lt[l];
    if(t[r] == (e - m)) rt[c] = t[r] + rt[l];
    else rt[c] = rt[r];
}
void query(int x, int y, int &ans, int &left, int &right, int c = 1, int b = 1, int e = n) {
    if(x <= b && e <= y) {
        ans = t[c];
        left = lt[c];
        right = rt[c];
        return ;
    }
    if(e < x || y < b) {
        ans = left = right = 0;
        return ;
    }
    int m = (b + e) >> 1;
    int l = c << 1;
    int r = l + 1;
    int as[2];
    int lf[2];
    int rg[2];
    query(x, y, as[0], lf[0], rg[0], l, b, m);
    query(x, y, as[1], lf[1], rg[1], r, m+1, e);
    ans = max(as[0], as[1]);
    ans = max(ans, rg[0] + lf[1]);
    if(as[0] == (m - b + 1)) left = as[0] + lf[1];
    else left = lf[0];
    if(as[1] == (e - m)) right = as[1] + rg[0];
    else right = rg[1];
    return ;  
}
int get(int x, int y) {
    int ans, left, right;
    query(x, y, ans, left, right);
    return ans;
}

class data {
public:
    int b, e, w;
    int idx;
    data (int b, int e, int w) : b(b), e(e), w(w) {}
    data () {}
};

vector <int> v[100010];
int res[100010];
int a[100010];
map <int, int> com;
int rev[100010];

void solve(int l, int r, vector <data> &can) {
    if(l == r) {
        for(int i : v[l]) {
            update(i, 1);
        }
        for(data i : can) {
            res[i.idx] = l;
        }
        return ;
    }
    int m = (l + r) >> 1;
    for(int i = r; i > m; i--) {
        for(int j : v[i]) {
            update(j, 1);
        }
    }
    vector <data> left, right;
    for(data i : can) {
        if(get(i.b, i.e) >= i.w) {
            right.push_back(i);
        } else {
            left.push_back(i);
        }
    }
    can.clear();
    for(int i = r; i > m; i--) {
        for(int j : v[i]) {
            update(j, 0);
        }
    }
    solve(m + 1, r, right);
    solve(l, m, left);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        com[a[i]];
    }
    int idx = 0;
    for(auto &i : com) {
        i.second = ++idx;
    }
    for(int i = 1; i <= n; i++) {
        int mem = a[i];
        a[i] = com[a[i]];
        v[a[i]].push_back(i);
        rev[a[i]] = mem;
    }
    vector <data> g;
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        data d;
        d.idx = i;
        scanf("%d %d %d", &d.b, &d.e, &d.w);
        g.push_back(d);
    }

    solve(1, idx, g);
    for(int i = 1; i <= m; i++) {
        printf("%d\n", rev[res[i]]);
    }
    return 0;
}