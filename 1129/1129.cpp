#include <iostream>
#include <list>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

int main() {
  int n, r, p, c;
  while(cin >> n >> r, n || r) {
    list<int> d;
    REP(i, n) d.push_back(n - i);
    REP(i, r) {
      cin >> p >> c;
      auto it = d.begin(), pos = it;
      REP(j, p - 1) it++;
      REP(j, c)
        pos = d.insert(pos, *it), it = d.erase(it), pos++;
    }
    cout << d.front() << endl;
  }
  return 0;
}
