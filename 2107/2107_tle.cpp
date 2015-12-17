#include <iostream>
#include <vector>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

vector<vector<bool> > get(vector<vector<bool> >& a) {
  int m = a.size(), p = m * m;
  vector<vector<bool> > res(p, vector<bool>(p, false));
  REP(i, m) REP(j, m) if(i != j)
    REP(k, m) if(i != k)
      res[i * m + j][j * m + k] = a[j][k];
  REP(i, m) res[0][i] = a[0][i];
  return res;
}

vector<vector<bool> > mul(vector<vector<bool> >& a) {
  int p = a.size();
  vector<vector<bool> > res(p, vector<bool>(p, false));
  REP(i, p) REP(j, p) REP(k, p)
    res[i][j] = res[i][j] | (a[i][k] & a[k][j]);
  return res;
}

bool solve(vector<vector<bool> > a, int n, int m, int z) {
  REP(i, z - 1) a = mul(a);
  REP(i, m * m) if(a[0][i * m + n - 1]) return true;
  return false;
}

int main() {
  int n, m, z, s, d;
  while(cin >> n >> m >> z, n || m || z) {
    vector<vector<bool> > g(n, vector<bool>(n, false));
    REP(i, m) cin >> s >> d, g[s - 1][d - 1] = g[d - 1][s - 1] = true;
    cout << ((solve(get(g), n, m, z))? "yes": "no") << endl;
  }
  return 0;
}
