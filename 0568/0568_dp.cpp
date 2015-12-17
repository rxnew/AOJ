#include <iostream>
#include <string.h>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int dp[101][3][2], m[101];
int n, k;

int func(int d, int p, int x) {
  if(d == 0) {
    if(m[0] != -1)
      return func(1, m[0], 0);
    else
      return (func(1, 0, 0) + func(1, 1, 0) + func(1, 2, 0)) % 10000;
  }

  if(d >= n)
    return 1;
  if(p == m[d] && x)
    return 0;
  if(dp[d][p][x] != -1)
    return dp[d][p][x];

  if(m[d] != -1)
    dp[d][p][x] = func(d + 1, m[d], !(p ^ m[d]));
  else if(x)
    dp[d][p][x] = func(d + 1, (p + 1) % 3, 0) + func(d + 1, (p + 2) % 3, 0);
  else
    dp[d][p][x] = func(d + 1, p, 1) + func(d + 1, (p + 1) % 3, 0) + func(d + 1, (p + 2) % 3, 0);

  return dp[d][p][x] %= 10000;
}

int main() {
  int d, p;

  memset(dp, -1, sizeof(dp));
  memset(m, -1, sizeof(m));

  cin >> n >> k;
  REP(i, k) {
    cin >> d >> p;
    m[d - 1] = p - 1;
  }
  
  cout << func(0, -1, 0) << endl;

  return 0;
}
