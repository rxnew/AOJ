#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, a, b, c, x;

  while(cin >> n >> a >> b >> c >> x, n || a || b || c || x) {
    int y[n], f = 0;

    REP(i, n)
      cin >> y[i];

    for(int i = 0; i < n && f <= 10001; x = (a * x + b) % c, f++)
      if(x == y[i])
	i++;

    cout << ((f <= 10001)? f - 1: -1) << endl;
  }

  return 0;
}
