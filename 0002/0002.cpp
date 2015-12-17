#include <iostream>
using namespace std;

int main() {
  int a, b, sum, n;

  while(cin >> a >> b) {
    sum = a + b;
    for(n = 1; sum >= 10; sum /= 10, n++);
    cout << n << endl;
  }

  return 0;
}
