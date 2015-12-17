#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  double a, l, x, s, res;

  while(cin >> a >> l >> x) {
    s = (l * 2 + a) / 2;
    res = sqrt(s * (s - a) * pow(s - l, 2));
    s = (l * 2 + x) / 2;
    res += (2 * sqrt(s * (s - l) * pow(s - ((l + x) / 2), 2)));
    cout << fixed << setprecision(10) << res << endl;
  }

  return 0;
}
