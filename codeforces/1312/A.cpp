#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << ((n % m) ? "NO" : "YES") << "\n";
    }
    return 0;
}