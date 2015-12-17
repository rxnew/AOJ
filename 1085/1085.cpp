#include <iostream>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int main() {
  int n, s;

  while(cin >> n >> s, n || s) {
    int ans = 0;
    int r[n];

    REP(i, n)
      cin >> r[i];
    
    REP(i, n) FOR(j, i + 1, n)
      if(s < r[i] + r[j])
	ans++;

    cout << ans << endl;
  }
    
  return 0;
}
