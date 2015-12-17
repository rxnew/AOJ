#include <iostream>
#include <vector>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

typedef vector<vector<bool> > Matrix;

Matrix get(Matrix& a) {
  int m = a.size(), p = m * m;
  Matrix res(p, vector<bool>(p, false));
  REP(i, m) REP(j, m) if(i != j)
    REP(k, m) if(i != k)
      res[i * m + j][j * m + k] = a[j][k];
  REP(i, m) res[0][i] = a[0][i];
  return res;
}

Matrix mul(Matrix& a, Matrix& b) {
  int p = a.size();
  Matrix res(p, vector<bool>(p, false));
  REP(i, p) REP(j, p) REP(k, p)
    res[i][j] = res[i][j] | (a[i][k] & b[k][j]);
  return res;
}

Matrix pow(Matrix& a, int n) {
  int p = a.size();
  Matrix res(p, vector<bool>(p, false));
  REP(i, p) res[i][i] = true;
  if(n == 0) return res;
  res = pow(a, n / 2);
  if(n % 2) res = mul(res, a);
  return res;
}

bool solve(Matrix a, int n, int m, int z) {
  a = pow(a, z);
  REP(i, m * m) if(a[0][i * m + n - 1]) return true;
  return false;
}

int main() {
  int n, m, z, s, d;
  while(cin >> n >> m >> z, n || m || z) {
    Matrix g(n, vector<bool>(n, false));
    REP(i, m) cin >> s >> d, g[s - 1][d - 1] = g[d - 1][s - 1] = true;
    cout << ((solve(get(g), n, m, z))? "yes": "no") << endl;
  }
  return 0;
}
