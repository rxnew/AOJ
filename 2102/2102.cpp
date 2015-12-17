#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define SORT(c) sort((c).begin(), (c).end())
#define MP make_pair
using namespace std;

typedef pair<int, char> P;
int  P::* n = &P::first;
char P::* c = &P::second;

bool meld(vector<P> *card, int func) {
  for(int i = 0, cnt = 0, rnum[3] = {0}; i < (*card).size(); i++, cnt = 0, rnum[0] = i) {
    for(int j = i + 1; j < (*card).size(); j++) {
      if((*card)[i].*n == (*card)[j].*n - ((func)? cnt + 1: 0) && (*card)[i].*c == (*card)[j].*c) {
	rnum[++cnt] = j;
	if(cnt == 2) {
	  REP(k, 3)
	    (*card).erase((*card).begin() + rnum[k] - k);
	  return true;
	}
      }
    }
  }

  return false;
}

bool meldPrime(vector<P> card, int func) {
  REP(i, 2)
    while(meld(&card, func ^ i));

  return (card.size())? false: true;
}

int main() {
  int t, ni;
  char ci;
  vector<P> card(9, MP(0, 'X'));

  cin >> t;

  while(t--) {
    REP(i, 2) REP(j, 9)
      ((!i)? cin >> ni: cin >> ci), card[j] = ((!i)? MP(ni, 'X'): MP(card[j].*n, ci));
    SORT(card);
    cout << ((meldPrime(card, 0) || meldPrime(card, 1))? 1: 0) << endl;
  }

  return 0;
}
