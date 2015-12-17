#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, num;

  while(cin >> n, n) {
    vector<int> cards[2];
    for(int i = 1; i <= n * 2; i++)
      cards[1].push_back(i);
    while(n--) {
      cin >> num;
      cards[1].erase(find(cards[1].begin(), cards[1].end(), num));
      cards[0].push_back(num);
    }
    sort(cards[0].begin(), cards[0].end());

    int field = 0, turn = 0;
    while(cards[0].size() && cards[1].size()) {
      bool clearFlg = true;
      for(vector<int>::iterator it = cards[turn].begin(); it != cards[turn].end(); it++) {
	if(field < *it) {
	  field = *it;
	  cards[turn].erase(it);
	  clearFlg = false;
	  break;
	}
      }
      if(clearFlg)
	field = 0;
      turn ^= 1;
    }

    for(int i = 1; i >= 0; i--)
      cout << cards[i].size() << endl;
  }

  return 0;
}
