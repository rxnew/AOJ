#include <iostream>
using namespace std;

int main() {
  int r, c;

  while(cin >> r >> c, r || c) {
    if(r % 2 && c % 2)
      cout << "no" << endl;
    else
      cout << "yes" << endl;
  }

  return 0;
}
