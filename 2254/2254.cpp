#include <iostream>
#include <vector>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define INF (1 << 21)

using namespace std;

int tsp(vector<vector<int> >& t, int n) {
  vector<int> dp(1 << n, INF);
  dp[0] = 0;
  REP(i, 1 << n) {
    REP(j, n) {
      int c = t[j][0];
      REP(k, n) if(i & 1 << k) c = min(c, t[j][k + 1]);
      dp[i | 1 << j] = min(dp[i | 1 << j], dp[i] + c);
    }
  }
  return dp[(1 << n) - 1];
}

int main() {
  int n;
  while(cin >> n, n) {
    vector<vector<int> > t(n, vector<int>(n + 1));
    REP(i, n) REP(j, n + 1) cin >> t[i][j];
    cout << tsp(t, n) << endl;
  }
  return 0;
}
