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
      /* 列車を分割 */
      sub[0] = train.substr(0, i + 1);
      sub[1] = train.substr(i + 1);

      REP(j, 4) {
	if(j)
	  /* 列車を反転 */
	  reverse(sub[j % 2].begin(), sub[j % 2].end());
	REP(k, 2) {
	  bool flg = true;
	  /* 列車を連結 */
	  tmp = sub[k ^ 0] + sub[k ^ 1];
	  /* 既存ではないか比較 */
	  for(int l = 0; l < reset.size() && flg; l++)
	    if(!tmp.compare(reset[l]))
	      flg = false;
	  /* リストに追加 */
	  if(flg)
	    reset.PB(tmp);
	}
      }
    }

    cout << reset.size() << endl;
  }
 
  return 0;
}
