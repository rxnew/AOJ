#include <iostream>
using namespace std;

int main() {
  int n, card[2], score[2];
  
  while(cin >> n, n) {
    score[0] = 0, score[1] = 0;
    while(n--) {
      cin >> card[0] >> card[1];
      if(card[0] > card[1])
	score[0] += (card[0] + card[1]);
      else if(card[0] < card[1])
	score[1] += (card[0] + card[1]);
      else
	score[0] += card[0], score[1] += card[1];
    }

    cout << score[0] << " " << score[1] << endl;
  }

  return 0;
}
