#include <bits/stdc++.h>
using namespace std;

using ll = long long;

auto solve(int n, const vector<vector<bool>>& d) -> int {
  vector<ll> m(n);
  for(int i = 0; i < n; i++) m[i] = ll(1) << i;
  for(int i = 1; i <= 30; i++) {
    vector<int> mi;
    ll f = 0;
    for(int j = 0; j < n; j++) if(d[j][i]) mi.push_back(j), f |= m[j];
    if(f == (ll(1) << n) - 1) return i;
    for(const auto& x : mi) m[x] = f;
  }
  return -1;
}

auto main() -> int {
  int n, fi, di;
  while(cin >> n, n) {
    vector<vector<bool>> d(n, vector<bool>(31, false));
    for(auto& x : d) {
      cin >> fi;
      for(int i = 0; i < fi; i++) cin >> di, x[di] = true;
    }
    cout << solve(n, d) << endl;
  }
  return 0;
}
