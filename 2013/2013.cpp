#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define PB push_back
#define MP make_pair
using namespace std;

int main() {
  int n, tmp[2];
  char buf[9], *p;

  while(cin >> n, n) {
    vector<pair<int, int> > time;
    int re[10001] = {0}, sum = n;

    REP(i, n) {
      REP(j, 2) {
	cin >> buf;
	tmp[j] = 0;
	for(int k = 0; (p = strtok(((k)? NULL : buf), ":")), k < 3; k++)
	  tmp[j] += atoi(p) * pow(60, (2 - k));
      }
      time.PB(MP(tmp[0], tmp[1]));
    }

    sort(time.begin(), time.end());
      
    REP(i, n - 1) {
      for(int j = i + 1; j < n; j++) {
	if(re[j] == 0 && time[i].second <= time[j].first) {
	  re[j] = 1;
	  break;
	}
      }
    }

    REP(i, n)
      sum -= re[i];

    cout << sum << endl;
  }

  return 0;
}
