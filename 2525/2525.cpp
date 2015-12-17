#include <iostream>
#include <cmath>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
  ll m, r[2], c[2];

  cin >> m >> r[0] >> r[1] >> c[0] >> c[1];

  REP(i, 2)
    m -= (ll)ceil((double)c[i] / (double)r[i] * 100);
  
  cout << ((m < 0)? (-1) : m) << endl;

  return 0;
}
