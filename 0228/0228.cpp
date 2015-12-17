#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

string dig(int num) {
  switch(num) {
  case 0: return "0111111";
  case 1: return "0000110";
  case 2: return "1011011";
  case 3: return "1001111";
  case 4: return "1100110";
  case 5: return "1101101";
  case 6: return "1111101";
  case 7: return "0100111";
  case 8: return "1111111";
  case 9: return "1101111";
  default: break;
  }
  return "0000000";
}

int main() {
  int n, num;

  while(cin >> n, n != -1) {
    string digit, state = "0000000";

    REP(i, n) {
      cin >> num;

      digit = dig(num);
      REP(j, 7) {
	if(state[j] == digit[j])
	  cout << 0;
	else
	  cout << 1;
      }
      cout << endl;

      state = digit;
    }
  }

  return 0;
}
