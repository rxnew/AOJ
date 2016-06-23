// UKP (Unbounded Knapsack Problem)
// DP
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

// x := (重さの最大値)
// w := (各要素の重み)
// v := (各要素の価値)
// dp[j] := (i番目までの要素を使って袋の総重量がj以下になるときの価値の最大値)
// dp[j] = max(dp[j], dp[j - w[i]] + v[i])
auto ukp(int n, int x, const vi& w, const vi& v) -> int {
  vi dp(x + 1, 0);
  for(int i = 0; i < n; i++) for(int j = w[i]; j <= x; j++)
    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
  return dp.back();
}

auto solve(int n, int d, int x, const vvi& p) -> int {
  vi v(n);
  for(int i = 0; i < d - 1; i++) {
    for(int j = 0; j < n; j++) v[j] = p[i + 1][j] - p[i][j];
    x += ukp(n, x, p[i], v);
  }
  return x;
}

auto main() -> int {
  int n, d, x;
  cin >> n >> d >> x;
  vvi p(d, vi(n));
  for(auto& pi : p) for(auto& pij : pi) cin >> pij;
  cout << solve(n, d, x, p) << endl;
  return 0;
}
