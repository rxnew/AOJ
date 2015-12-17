#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define PB push_back
using namespace std;

int main() {
  int m;

  cin >> m;

  while(m--) {
    string train, sub[2], tmp;
    vector<string> reset;

    cin >> train;

    REP(i, train.size() - 1) {
      sub[0] = train.substr(0, i + 1);
      sub[1] = train.substr(i + 1);

      REP(j, 4) {
	if(j)
	  reverse(sub[j % 2].begin(), sub[j % 2].end());
	REP(k, 2) {
	  bool flg = true;
	  tmp = sub[k ^ 0] + sub[k ^ 1];
	  for(int l = 0; l < reset.size() && flg; l++)
	    if(!tmp.compare(reset[l]))
	      flg = false;
	  if(flg)
	    reset.PB(tmp);
	}
      }
    }

    cout << reset.size() << endl;
  }
 
  return 0;
}
