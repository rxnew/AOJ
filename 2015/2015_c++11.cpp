#include <iostream>
#include <vector>
#include <numeric>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

vector<int> get(vector<int>& v) {
  vector<int> res(accumulate(v.begin(), v.end(), 0) + 1, 0);
  REP(i, v.size()) {
    int sum = 0;
    FOR(j, i, v.size()) res[(sum += v[j])]++;
  }
  return res;
}

int solve(vector<int>&& a, vector<int>&& b) {
  int res = 0;
  REP(i, min(a.size(), b.size())) res += a[i] * b[i];
  return res;
}

int main() {
  int n, m;
  while(cin >> n >> m, n || m) {
    vector<int> h(n), w(m);
    REP(i, n) cin >> h[i];
    REP(i, m) cin >> w[i];
    cout << solve(get(h), get(w)) << endl;
  }
  return 0;
}
