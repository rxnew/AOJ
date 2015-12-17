#include <iostream>
#include <vector>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

vector<int> get(vector<int>& v) {
  int sum = 0;
  REP(i, v.size()) sum += v[i];
  vector<int> a(sum + 1, 0);
  REP(i, v.size()) {
    int sum = 0;
    FOR(j, i, v.size()) a[(sum += v[j])]++;
  }
  return a;
}

int solve(vector<int>& h, vector<int>& w) {
  vector<int> a = get(h), b = get(w);
  int result = 0;
  REP(i, min(a.size(), b.size())) result += a[i] * b[i];
  return result;
}

int main() {
  int n, m;
  while(cin >> n >> m, n || m) {
    vector<int> h(n), w(m);
    REP(i, n) cin >> h[i];
    REP(i, m) cin >> w[i];
    cout << solve(h, w) << endl;
  }
  return 0;
}
