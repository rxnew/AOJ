#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define PB push_back

using namespace std;

int main() {
  int t, n, h, p;
  cin >> t;
  while(t--) {
    cin >> n >> p;
    vector<int> d(1, 0);
    REP(i, n - 1)
      cin >> h, d.PB(p - h), p = h;
    sort(d.begin(), d.end());
    cout << abs(d.front()) << " " << d.back() << endl;
  }
  return 0;
}
