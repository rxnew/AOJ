#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, hit;

  while(cin >> n, n) {
    int sum = 0;

    REP(i, n / 4) {
      cin >> hit;
      sum += hit;
    }

    cout << sum << endl;
  }

  return 0;
}
