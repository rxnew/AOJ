#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

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
