#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long b[maxn];
long long a[maxn];
int n;
int cnt;
map <tuple <int, int, int>, long long> save;

long long ask(int i, int j, int k) {
  if(i > j) swap(i, j);
  if(j > k) swap(j, k);
  if(i > j) swap(i, j);
  if(save.find(make_tuple(i, j, k)) != save.end()) return save[make_tuple(i, j, k)];
  cout << "? " << i << " " << j << " " << k << endl;
  long long ans;
  cin >> ans;
  return save[make_tuple(i, j, k)] = ans;
}

void solveTheRest(int opt, int secondOpt) {
  vector <int> found;
  for(int i = 1; i <= n; i++) if(i != opt && i != secondOpt) found.push_back(i);
  for(auto i : found) {
    b[i] = ask(i, secondOpt, opt);
  }
  sort(found.begin(), found.end(), [&] (int i, int j) {
      return b[i] < b[j]; } );
  b[opt] = (b[found[0]] + b[found[2]] - ask(found[0], found[1], found[2])) / 2;
  for(auto i : found) b[i] -= b[opt];
  b[secondOpt] = ask(found[0], found[1], secondOpt) - b[found[0]];
  cout << "! ";
  for(int i = 1; i <= n; i++) cout << b[i] << " ";
  cout << endl;
}
bool check(map <int, long long> com, vector <int> v) {
  for(auto i : com) if(i.second < 0) return false;
  for(int i : v) for(int j : v) for(int k : v) if(i != j && j != k && k != i) {
    if(min({com[i], com[j], com[k]}) + max({com[i], com[j], com[k]}) != ask(i, j, k)) return false;
  }
  return true;
}
pair <int, int> getTopTwo(vector <int> v) {
  for(int i : v) {
    for(int j : v) {
      for(int k : v) {
        if(i == j || j == k || k == i) continue;
        vector <int> u = v;
        for(auto x : {i, j, k}) {
          u.erase(find(u.begin(), u.end(), x));
        }
        sort(u.begin(), u.end(), [&] (int p, int q) {
            return ask(p, j, k) < ask(q, j, k); } );
        map <int, long long> com;
        com[k] = (ask(u[0], j, k) + ask(i, j, k) - ask(u[0], u[1], i)) / 2;
        for(auto x : u) {
          com[x] = ask(x, j, k) - com[k];
        }
        com[i] = ask(i, j, k) - com[k];
        com[j] = ask(u[0], u[1], j) - com[u[0]];
        if(check(com, v)) {
          vector <pair <long long, int>> aux;
          for(auto x : com) aux.emplace_back(-x.second, x.first);
          sort(aux.begin(), aux.end());
          return make_pair(aux[0].second, aux[1].second);
        }
      }
    }
  }
  return make_pair(-1, -1);
}
int main() {
  cin >> n;
  int opt = -1;
  long long sum = -1;
  for(int i = 3; i <= n; i++) {
    if(sum < ask(1, 2, i)) {
      sum = ask(1, 2, i);
      opt = i;
    }
  }
  vector <int> can ({1, 2, opt});
  int newOpt = -1;
  sum = -1;
  for(int i = 3; i <= n; i++) {
    if(i != opt) {
      if(can.size() < 5) can.push_back(i);
      else {
        auto var = ask(*(can.end() - 1), *(can.end() - 2), i);
        if(sum < var) {
          sum = var;
          newOpt = i;
        }
      }
    }
  }
  if(newOpt != -1) can.push_back(newOpt);
  int firstMax, secondMax;
  tie(firstMax, secondMax) = getTopTwo(can);
  solveTheRest(firstMax, secondMax);
  return 0;
}
