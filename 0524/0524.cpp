#include <iostream>
#include <vector>
#include <algorithm>
 
#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define MP make_pair
#define PB push_back
 
using namespace std;
 
int main() {
  int m, n, x, y;
 
  while(cin >> m, m) {
    vector<pair<int, int> > star, pict;
    REP(i, m) {
      cin >> x >> y;
      star.PB(MP(x, y));
    }
    cin >> n;
    REP(i, n) {
      cin >> x >> y;
      pict.PB(MP(x, y));
    }
 
    sort(ALL(star)), sort(ALL(pict));
 
    REP(i, n) {
      bool result = true;
      x = pict[i].first - star[0].first;
      y = pict[i].second - star[0].second;
      FOR(j, 1, m) {
        int k;
        for(k = j; k < n; k++)
          if(pict[k] == MP(star[j].first + x, star[j].second + y))
            break;
        if(k == n) {
          result = false;
          break;
        }
      }
      if(result)
        break;
    }
 
    cout << x << " " << y << endl;
  }
 
  return 0;
}
