#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
  int n, order;
  string name;
  cin >> n;
  auto cmp = [](const string& l, const string& r) {return l.size() == r.size() ? l < r : l.size() < r.size();};
  map<string, int, decltype(cmp)> m(cmp);
  while(n--) cin >> name >> order, m[name] += order;
  for(auto v : m) cout << v.first << ' ' << v.second << endl;
  return 0;
}
