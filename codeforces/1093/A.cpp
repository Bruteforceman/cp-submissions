#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int x;
        scanf("%d", &x);
        if(x <= 7) {
            printf("1\n");
        } else {
            if(x % 2 == 0) {
                printf("%d\n", x/2);
            } else {
                printf("%d\n", 1 + ((x-3) / 2));
            }
        }
    }
}
