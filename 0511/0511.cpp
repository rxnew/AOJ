#include <iostream>
using namespace std;

int main() {
  int num;
  bool n[30] = {false};

  for(int i = 0; i < 28; i++) {
    cin >> num;
    n[num - 1] = true;
  }

  for(int i = 0; i < 30; i++) {
    if(!n[i])
      cout << i + 1 << endl;
  }
  
  return 0;
}
