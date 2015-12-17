#include <iostream>
using namespace std;

int main() {
  int n, x, y, b, p, tmp, price;
  
  cin >> n;

  while(n--) {
    cin >> x >> y >> b >> p;

    if(b >= 5 && p >= 2)
      price = (int)((x * b + y * p) * 0.8);
    else {
      tmp = (int)((x * 5 + y * 2) * 0.8);
      if(b - 5 > 0)
	tmp += (int)(x * (b - 5) * 0.8);
      if(p - 2 > 0)
	tmp += (int)(y * (p - 2) * 0.8);
      price = min(tmp, (x * b + y * p));
    }

    cout << price << endl;
  }

  return 0;
}
