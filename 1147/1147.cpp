#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
  int n;
  while(cin >> n, n) {
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    sort(v.begin(), v.end());
    cout << accumulate(++v.begin(), --v.end(), 0) / (v.size() - 2) << endl;
  }
  return 0;
}
