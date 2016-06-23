#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
  double d;
  cin >> d;
  cout << fixed
       << setprecision(12)
       << max(sqrt(d * d / 2) * 2, floor(d) + 1)
       << endl;
  return 0;
}
