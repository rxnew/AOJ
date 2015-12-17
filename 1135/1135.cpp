#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int cal(int f, int y, int s, double r, int c) {
  int inte = 0;

  REP(i, y)
    inte += f * r, f += f * ((s)? r: 0) - c;

  return f + ((s)? 0: inte);
}

int main() {
  int m, n, f, y, s, c, ans;
  double r;

  cin >> m;
  
  while(ans = 0, m--) {
    cin >> f >> y >> n;
    while(n--)
      cin >> s >> r >> c, ans = max(ans, cal(f, y, s, r, c));
    cout << ans << endl;
  }

  return 0;
}
