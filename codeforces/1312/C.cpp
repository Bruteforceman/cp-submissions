#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        set <int> s;
        bool bad = false;
        for(int i = 0; i < n; i++) {
            long long x;
            scanf("%lld", &x);
            int pos = 0;
            while(x) {
                int d = x % k;
                if(d > 1) bad = true;
                else if (d == 1) {
                    if(s.find(pos) != s.end()) bad = true;
                    s.insert(pos);
                }
                x /= k;
                ++pos;
            }
        }
        if(bad) puts("NO");
        else puts("YES");
    }
}