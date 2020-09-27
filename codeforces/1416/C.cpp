#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int maxb = 31;
int a[maxn];
int n;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
pair <int, long long> solve(int bit) {
  int mask = 0;
  for(int i = bit + 1; i < maxb; i++) {
    mask |= 1 << i;
  }
  unordered_map<long long, int, custom_hash> cnt[2];
  for(int i = 0; i < 2; i++) {
    cnt[i].reserve(n);
    cnt[i].max_load_factor(0.25);
  }
  long long ans[2] = {0, 0};
  for(int i = 0; i < n; i++) {
    int pre = mask & a[i];
    int val = (a[i] >> bit) & 1;
    if(val == 0) {
      ans[0] += cnt[1][pre];
    } else {
      ans[1] += cnt[0][pre];
    }
    cnt[val][pre] += 1;
  }
  if(ans[0] > ans[1]) return make_pair(1, ans[1]);
  else return make_pair(0, ans[0]);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  long long total = 0;
  int opt = 0;
  for(int i = 0; i < maxb; i++) {
    auto x = solve(i);
    total += x.second;
    if(x.first) opt |= 1 << i;
  }
  printf("%lld %d\n", total, opt);
}
