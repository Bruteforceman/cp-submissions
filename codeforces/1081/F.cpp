#include <bits/stdc++.h>
using namespace std;
int a[333];
int n, T;
int tot;

int ask(int l, int r) {
    /*if(rand() & 1) {
        for(int i = l; i <= n; i++) {
            a[i] ^= 1;
        }
    } else {
        for(int i = 1; i <= r; i++) {
            a[i] ^= 1;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt += a[i];
        //cout << a[i];
    }*/
    //cout << endl;
    ++tot;
    assert(tot <= 10000);
    cout << "? " << l << " " << r << endl;
    int cnt;
    cin >> cnt;
    return cnt;
}

int b[333];
int p[333];

void solve() {
    int last = T;
    for(int i = (n & 1) ? 2 : 1; i <= n; i++) {
        int l = (n & 1) ? i-1 : i;
        int r = i;
        int c1 = 0, c2 = 0;
        while(true) {
            int t = ask(l, r);
            bool good = false;
            if((abs(t - last) & 1) == (r & 1)) good = true;
            if(c1 == 0 && c2 == 0 && good) {
                p[i] = (last - t + r) / 2;
                // cout << i << ": " << p[i] << endl;
            }
            if(good) {
                c1 ^= 1;
            } else {
                c2 ^= 1;
            }
            last = t;
            if(c1 == 1 && c2 == 0 && good) break;
        }
        while(c1 != 0 || c2 != 0) {
            int t = ask(l, r);
            bool good = false;
            if((abs(t - last) & 1) == (r & 1)) good = true;
            if(good) {
                c1 ^= 1;
            } else {
                c2 ^= 1;
            }
            last = t;
        }
    }
    if(n & 1) {
        int val = 0;
        int c1 = 0, c2 = 0;
        while(true) {
            int t = ask(2, 3);
            bool good = false;
            if((abs(t - last) & 1) == 0) good = true;
            if(c1 == 0 && c2 == 0 && good) {
                val = (last - t + (n - 1)) / 2;
            }
            if(good) {
                c1 ^= 1;
            } else {
                c2 ^= 1;
            }
            last = t;
            if(c1 == 1 && c2 == 0 && good) break;
        }
        p[1] = T - val;
    }
    cout << "! ";
    for(int i = 1; i <= n; i++) {
        cout << p[i] - p[i-1];
    }
    cout << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n >> T;
    if(n == 1) {
        cout << "! " << T << endl;
        exit(0);
    }
    solve();
}