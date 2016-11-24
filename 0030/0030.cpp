#include <bits/stdc++.h>
using namespace std;

auto dfs(int n, int s, int a) -> int {
  if(!n) return s ? 0 : 1;
  auto res = 0;
  for(auto i = a; i <= 9; ++i) {
    res += dfs(n - 1, s - i, i + 1);
  }
  return res;
}

auto main() -> int {
  int n, s;
  while(cin >> n >> s, n || s) {
    cout << dfs(n, s, 0) << endl;
  }
  return 0;
}
