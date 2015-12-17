#include <iostream>
using namespace std;

int main() {
  int n, k, a, b, ans;

  cin >> n >> k;
  while(k--) {
    cin >> a >> b;
    if(a > (n + 1) / 2)
      a = n - a + 1;
    if(b > (n + 1) / 2)
      b = n - b + 1;
    if((ans = min(a, b) % 3))
      cout << ans << endl;
    else
      cout << "3" << endl;
  }

  return 0;
}
