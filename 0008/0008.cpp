#include <bits/stdc++.h>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int main() {
  int n;
  while(cin >> n) {
    int ans = 0;
    REP(a, 10) REP(b, 10) REP(c, 10) REP(d, 10)
      if(a + b + c + d == n) ans++;
    cout << ans << endl;
  }
  return 0;
}
