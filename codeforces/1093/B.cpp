#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int idx = -1;
        for(int i = 1; i < (int) s.size(); i++) {
            if(s[i] != s[0]) {
                idx = i;
                break;
            }
        }
        if(idx == -1) {
            cout << -1 << endl;
        } else {
            swap(s[idx], s[s.size() - 1]);
            cout << s << endl;
        }
    }
    return 0;
}
