#include <iostream>
using namespace std;

int main() {
  int n;

  while(cin >> n, n) {
    int ans = 0;
    
    for(int i = 5; i <= n; i *= 5)
      ans += n / i;

    cout << ans << endl;
  }

  return 0;
}
