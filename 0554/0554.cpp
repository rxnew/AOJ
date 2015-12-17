#include <iostream>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int main() {
  int sum = 0, s;

  REP(i, 4) {
    cin >> s;
    sum += s;
  }

  cout << sum / 60 << endl << sum % 60 << endl;

  return 0;
}
