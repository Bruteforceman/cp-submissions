#include <bits/stdc++.h>
using namespace std;
int opt[200010 * 4];
int mn[1 << 4][4 * 200010];
int mx[1 << 4][4 * 200010];
int a[5][200010];
int n, k;
const int inf = 1e9;

void update(int x, int c = 1, int b = 1, int e = n) {
    if(b == e) {
        for(int i = 0; i < (1 << (k-1)); i++) {
            mx[i][c] = a[k-1][b];
            mn[i][c] = a[k-1][b];
            for(int j = 0; j < k-1; j++) {
                if((i >> j) & 1) {
                    mx[i][c] += a[j][b];
                    mn[i][c] += a[j][b];
                } else {
                    mx[i][c] -= a[j][b];
                    mn[i][c] -= a[j][b];
                }
            }
        }
        return ;
    }
    int m = (b + e) >> 1;
    int l = c << 1;
    int r = l + 1;
    if(x <= m) {
        update(x, l, b, m);
    } else {
        update(x, r, m+1, e);
    }
    opt[c] = max(opt[l], opt[r]);
    for(int i = 0; i < (1 << (k-1)); i++) {
        mx[i][c] = max(mx[i][l], mx[i][r]);
        mn[i][c] = min(mn[i][l], mn[i][r]);
        opt[c] = max(opt[c], mx[i][l] - mn[i][r]);
        opt[c] = max(opt[c], mx[i][r] - mn[i][l]);
    }
}
struct data {
    int mx[1 << 4];
    int mn[1 << 4];
    int opt;
    data () {
        opt = -inf;
        for(int i = 0; i < (1 << (k-1)); i++) {
            mx[i] = -inf;
            mn[i] = inf;
        }
    }
};

data query(int x, int y, int c = 1, int b = 1, int e = n) {
    if(x <= b && e <= y) {
        data ans;
        for(int i = 0; i < (1 << (k-1)); i++) {
            ans.mx[i] = mx[i][c];
            ans.mn[i] = mn[i][c];
            ans.opt = opt[c];
        }
        return ans;
    }
    if(y < b || e < x) return data();
    int m = (b + e) >> 1;
    int l = c << 1;
    int r = l + 1;
    data p = query(x, y, l, b, m);
    data q = query(x, y, r, m+1, e);
    data ans;
    ans.opt = max(p.opt, q.opt);
    for(int i = 0; i < (1 << (k-1)); i++) {
        ans.mn[i] = min(p.mn[i], q.mn[i]);
        ans.mx[i] = max(p.mx[i], q.mx[i]);
        ans.opt = max(ans.opt, p.mx[i] - q.mn[i]);
        ans.opt = max(ans.opt, q.mx[i] - p.mn[i]);
    }
    return ans;
}

int main() {
    // freopen("in.txt", "r", stdin);

    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            scanf("%d", &a[j][i]);
        }
        update(i);
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int c;
        scanf("%d", &c);
        if(c == 1) {
            int idx;
            scanf("%d", &idx);
            for(int i = 0; i < k; i++) {
                scanf("%d", &a[i][idx]);
            }
            update(idx);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            data ans = query(l, r);
            printf("%d\n", ans.opt);
        }
    }
    return 0;
}
