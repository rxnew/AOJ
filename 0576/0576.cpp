#include <iostream>
using namespace std;
 
int main() {
  int L, A, B, C, D;
  cin >> L >> A >> B >> C >> D;
  cout << L - max((A + C - 1) / C, (B + D - 1) / D) << endl;
  return 0;
}