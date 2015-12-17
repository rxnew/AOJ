#include <iostream>
using namespace std;

int main() {
  int res, book;

  while(cin >> res, res) {
    for(int i = 0; i < 9; i++) {
      cin >> book;
      res -= book;
    }

    cout << res << endl; 
  }
  return 0;
}
