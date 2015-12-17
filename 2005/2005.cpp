#include <iostream>
#include <vector>
#include <climits>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

int n, m, s, g1, g2;

/* Warshall-Floyd Algorithm */
vector<vector<int> > calc(vector<vector<int> > d) {
  REP(i, n) REP(j, n) REP(k, n)
    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
  return d;
}

int solve(vector<vector<int> > d) {
  int res = INT_MAX;
  REP(i, n) res = min(res, d[s - 1][i] + d[i][g1 - 1] + d[i][g2 - 1]);
  return res;
}

int main() {
  int b1, b2, c;
  while(cin >> n >> m >> s >> g1 >> g2, n || m || s || g1 || g2) {
    vector<vector<int> > d(n, vector<int>(n, INT_MAX / 3));
    REP(i, n) d[i][i] = 0;
    REP(i, m) cin >> b1 >> b2 >> c, d[b1 - 1][b2 - 1] = c;
    cout << solve(calc(d)) << endl;
  }
  return 0;
}
