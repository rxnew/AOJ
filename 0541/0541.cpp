#include <iostream>
#include <vector>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int h, w, n, hi, wj;
  
  while(cin >> h >> w >> n, h || w || n) {
    int f[h][w];
    vector<vector<int> > dp(h, vector<int>(w, 0));

    REP(i, h) REP(j, w)
      cin >> f[i][j];
  
    dp[0][0] = n - 1;
    REP(i, h) {
      REP(j, w) {
	if(dp[i][j] % 2)
	  f[i][j] ^= 1;
	if(i < h - 1)
	  dp[i + 1][j] += dp[i][j] / 2 + ((dp[i][j] % 2)? f[i][j] ^ 0: 0);
	if(j < w - 1)
	  dp[i][j + 1] += dp[i][j] / 2 + ((dp[i][j] % 2)? f[i][j] ^ 1: 0);
      }
    }
    for(hi = 0, wj = 0; hi < h && wj < w; )
      (f[hi][wj])? wj++: hi++;

    cout << ++hi << " " << ++wj << endl;
  }
  
  return 0;
}
