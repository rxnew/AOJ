#include <iostream>
using namespace std;
 
int main() {
  const int value = 1000, coin[6] = {500, 100, 50, 10, 5, 1};
  int pay;
 
  while(cin >> pay, pay) {
    int num = 0;
    int change = value - pay;
    for(int i = 0; change; i++) {
      num += change / coin[i];
      change %= coin[i];
    }
    cout << num << endl;
  }
 
  return 0;
}
