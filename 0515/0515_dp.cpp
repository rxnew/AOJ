#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
  int a, b, n, x, y;
  while(cin >> a >> b, a || b) {
    vector<vector<int>> dp(a + 1, vector<int>(b + 1)), f(dp);
    cin >> n;
    while(n--) cin >> x >> y, f[x][y] = 1;
    for(int i = 1; i <= a; i++)
      for(int j = 1; j <= b; j++)
        if(!f[i][j]) dp[i][j] = (i | j) - 1 ? dp[i - 1][j] + dp[i][j - 1] : 1;
    cout << dp[a][b] << endl;
  }
  return 0;
}
