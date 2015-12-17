#include <bits/stdc++.h>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int main() {
  int n, m[2001] = {0};
  REP(i, 1001) REP(j, 1001) m[i + j]++;
  while(cin >> n) {
    int ans = 0;
    FOR(ab, max(0, n - 2000), 2001) {
      int cd = n - ab;
      if(cd < 0) break;
      ans += m[ab] * m[cd];
    }
    cout << ans << endl;
  }
  return 0;
}
