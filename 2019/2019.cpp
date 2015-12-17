#include <iostream>
#include <queue>
#include <map>
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
using namespace std;

int main() {
  int n, m, d, p, tmp;

  for(int res = 0; cin >> n >> m, n || m; res = 0) {
    priority_queue<pair<int, int> > pd;

    REP(i, n) {
      cin >> d >> p;
      pd.push(MP(p, d));
    }

    while(pd.size()) {
      if(m) {
	if(m >= (tmp = (pd.top()).second))
	  m -= tmp, pd.pop();
	else
	  res += (tmp - m) * (pd.top()).first, m = 0, pd.pop();
      }
      else
	res += (pd.top()).first * (pd.top()).second, pd.pop();
    }

    cout << res << endl;
  }

  return 0;
}
