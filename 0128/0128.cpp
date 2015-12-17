#include <iostream>
#include <cmath>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int in, n[5];

  for(int set = 0; cin >> in; set++) {
    if(set)
      cout << endl;
    REP(i, 5)
      n[i] = in / pow(10, 4 - i), in %= (int)pow(10, 4 - i);
    REP(i, 5)
      cout << ((n[i] >= 5)? ' ': '*');
    cout << endl;
    REP(i, 5)
      cout << ((n[i] >= 5)? '*': ' ');
    cout << endl;
    cout << "=====" << endl;
    REP(i, 5) {
      REP(j, 5)
	cout << (((n[j] - i) % 5)? '*': ' ');
      cout << endl;
    }
  }

  return 0;
}
