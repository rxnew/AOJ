#include <iostream>
#include <vector>
#define FOR(i, a, n) for(int i = (int)a; i < (int)n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

int solve(int h, int w, vector<vector<int> >& dp) {
  REP(i, w - 1) dp[0][i + 1] += dp[0][i];
  REP(i, h - 1) dp[i + 1][0] += dp[i][0];
  FOR(i, 1, h) FOR(j, 1, w) dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
  return dp.back().back();
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> field(h);
  REP(i, h) cin >> field[i];
  vector<vector<int> > dp(h, vector<int>(w));
  REP(i, h) REP(j, w) dp[i][j] = field[i][j] - '0';
  cout << solve(h, w, dp) << endl;
  return 0;
}
