#include <bits/stdc++.h>
using namespace std;

const int M = 1000000;
array<int, M> dp, odp;

auto init() -> void {
  for(int i = 0; i < M; i++) dp[i] = odp[i] = i;
  for(int n = 1, p = 1; p < M; n++, p = n * (n + 1) * (n + 2) / 6) {
    for(int i = 0; i + p < M; i++) {
      dp[i + p] = min(dp[i + p], dp[i] + 1);
      if(p % 2) odp[i + p] = min(odp[i + p], odp[i] + 1);
    }
  }
}

auto main() -> int {
  init();
  int n;
  while(cin >> n, n) cout << dp[n] << ' ' << odp[n] << endl;
  return 0;
}
