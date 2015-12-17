#include <iostream>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int main() {
  int p, j, min_p = 100000, min_j = 100000;

  REP(i, 3) {
    cin >> p;
    min_p = min(p, min_p);
  }
  REP(i, 2) {
    cin >> j;
    min_j = min(j, min_j);
  }

  cout << min_p + min_j - 50 << endl;

  return 0;
}
