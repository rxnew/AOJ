#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

constexpr auto INF = numeric_limits<int>::max();

inline auto add(int lhs, int rhs) -> int {
  return lhs == INF || rhs == INF ? INF : lhs + rhs;
}

auto tsp(int V, const vvi& d) -> int {
  vvi dp(1 << V, vi(V, INF));
  dp.back()[0] = 0;
  for(int S = (1 << V) - 1; S >= 0; S--) REP(v, V) REP(u, V)
    if(!(S & 1 << u)) dp[S][v] = min(dp[S][v], add(dp[S | 1 << u][u], d[v][u]));
  return dp[0][0];
}

auto main() -> int {
  int V, E, si, ti, di;
  cin >> V >> E;
  vvi d(V, vi(V, INF));
  while(cin >> si >> ti >> di) d[si][ti] = di;
  cout << [](int x){return x == INF ? -1 : x;}(tsp(V, d)) << endl;
  return 0;
}
