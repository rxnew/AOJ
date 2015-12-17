#include <iostream>
using namespace std;

int main() {
  int k;
  
  while(cin >> k, k) {
    int c, ci, csum = 0;

    ci = (k * (k - 1)) / 2;
    for(int i = 0; i < ci; i++) {
      cin >> c;
      csum += c;
    }

    csum /= (k - 1);
    cout << csum << endl;
  }

  return 0;
}
