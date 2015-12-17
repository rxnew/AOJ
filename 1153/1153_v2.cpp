#include <iostream>
#include <vector>
#include <numeric>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define SUM(v) accumulate(v.begin(), v.end(), 0)

using namespace std;

int main() {
  int n, m;
  while(cin >> n >> m, n || m) {
    vector<int> t(n), h(m), a(2, 101);
    REP(i, n) cin >> t[i]; REP(i, m) cin >> h[i];
    int diff = SUM(t) - SUM(h);
    REP(i, n) REP(j, m)
      if((t[i] - h[j]) * 2 == diff && t[i] + h[j] < SUM(a))
        a[0] = t[i], a[1] = h[j];
    a[0] != 101? cout << a[0] << ' ' << a[1] << endl: cout << -1 << endl;
  }
  return 0;
}
