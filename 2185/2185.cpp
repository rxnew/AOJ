#include <iostream>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define R(a, x, p) a >= x && a <= x + p
using namespace std;

int main() {
  int d, n, x, y, w, h, cx, cy;
  for(cin >> d; d; d--) {
    int ans = 0;
    cin >> x >> y >> w >> h >> n;
    REP(i, n) cin >> cx >> cy, R(cx, x, w) && R(cy, y, h) ? ans++ : 0;
    cout << ans << endl;
  }
  return 0;
}
