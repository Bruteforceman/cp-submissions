///usr/bin/g++ -O2 $0 -o ${0%.cpp} && echo "----------" && ./${0%.cpp}; exit;
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

const int N = 1e5 + 10; 

struct PT { 
    ll x, y; 
    PT(ll x = 0, ll y = 0) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
    bool operator != (const PT &p) const {
        return x != p.x || y != p.y;
    }
} p[N];

int main(int argc, char const *argv[]) {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }   

    p[n] = p[0];

    if(n & 1) {
        puts("NO");
        return 0;
    }

    bool found = 1; 
    for(int i = 0; i < n/2 && found; ++i) {
        if(p[i + 1] - p[i] != p[i + n/2] - p[i + n/2 + 1])
            found = 0;
    }

    puts(found ? "YES" : "NO");
}