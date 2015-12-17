#include <iostream>
#include <vector>

#define FOR(i, a ,n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define PB push_back

using namespace std;

int main() {
  int n, m, p1, p2;

  while(cin >> n, n) {
    vector<int> list[n];
    bool used[n], myfriend[n];
    int num = 0;

    REP(i, n) {
      used[i] = false;
      myfriend[i] = false;
    }
    used[0] = true;

    cin >> m;
    REP(i, m) {
      cin >> p1 >> p2;
      list[p1 - 1].PB(p2 - 1);
      list[p2 - 1].PB(p1 - 1);
    }

    REP(i, list[0].size()) {
      if(!used[list[0][i]]) {
	used[list[0][i]] = true;
	myfriend[list[0][i]] = true;
	num++;
      }
    }
    FOR(i, 1, n) {
      if(!myfriend[i])
	continue;
      REP(j, list[i].size()) {
	if(!used[list[i][j]]) {
	  used[list[i][j]] = true;
	  num++;
	}
      }
    }

    cout << num << endl;
  }

  return 0;
}
