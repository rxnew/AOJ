#include <iostream>
#include <string.h>
using namespace std;

int dp[101][101][2][2], w, h;

int func(int cw, int ch, int s, int d) {
  if(cw >= w || ch >= h)
    return 0;
  if(cw == w - 1 && ch == h - 1)
    return 1;
  if(dp[cw][ch][s][d])
    return dp[cw][ch][s][d];

  int r = d ^ 1;
  if(s)
    dp[cw][ch][s][d] = func(cw + d, ch + r, 0, d);
  else
    dp[cw][ch][s][d] = func(cw + d, ch + r, 0, d) + func(cw + r, ch + d, 1, r);

  return dp[cw][ch][s][d] %= 100000;
}

int main() {
  while(cin >> w >> h, w || h) {
    memset(dp, 0, sizeof(dp));
    cout << (func(0, 1, 0, 0) + func(1, 0, 0, 1)) % 100000 << endl;
  }

  return 0;
}
