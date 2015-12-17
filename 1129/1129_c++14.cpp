#include <iostream>
#include <list>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

int main() {
  auto f = [](auto it, int n){REP(i, n) it++; return it;};
  int n, r, p, c;
  while(cin >> n >> r, n || r) {
    list<int> d;
    REP(i, n) d.push_back(n - i);
    REP(i, r) {
      cin >> p >> c;
      auto pos1 = f(d.begin(), p - 1), pos2 = f(pos1, c);
      d.insert(d.begin(), pos1, pos2);
      d.erase(pos1, pos2);
    }
    cout << d.front() << endl;
  }
  return 0;
}
