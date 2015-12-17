#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
  int a, b;
  function<int(int, int)>
    gcd = [&](int a, int b) {return b ? gcd(b, a % b) : a;},
    lcm = [&](int a, int b) {return a / gcd(a, b) * b;};
  while(cin >> a >> b) cout << gcd(a, b) << ' ' << lcm(a, b) << endl;
  return 0;
}
