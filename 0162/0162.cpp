#include <iostream>
using namespace std;

int main() {
  int m, n;

  while(cin >> m, m) {
    cin >> n;
    int ans = 0;
    for(int i = m; i <= n; i++) {
      int hm = i;
      while((hm % 5) == 0)
	hm /= 5;
      while((hm % 3) == 0)
	hm /= 3;
      while((hm % 2) == 0)
	hm /= 2;
      if(hm == 1)
	ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
