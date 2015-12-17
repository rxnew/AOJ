#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int win_hund, hund[5];

  while(cin >> hund[0], hund[0]) {
    bool aiko_flg = false, win_flg = false;

    REP(i, 4)
      cin >> hund[i + 1];

    REP(i, 4) {
      if(hund[i] == hund[i + 1])
	continue;
      else if((hund[i] < hund[i + 1] && hund[i + 1] - hund[i] == 1) || (hund[i] > hund[i + 1] && hund[i] - hund[i + 1] == 2)) {
	if(win_flg && win_hund != hund[i]) {
	  aiko_flg = true;
	  break;
	}
	win_hund = hund[i], win_flg = true;
      }
      else {
	if(win_flg && win_hund != hund[i + 1]) {
	  aiko_flg = true;
	  break;
	}
	win_hund = hund[i + 1], win_flg = true;
      }
    }

    if(aiko_flg || !win_flg)
      REP(i, 5)
	cout << "3" << endl;
    else {
      REP(i, 5) {
	if(hund[i] == win_hund)
	  cout << "1" << endl;
	else
	  cout << "2" << endl;
      }
    }
  }

  return 0;
}
