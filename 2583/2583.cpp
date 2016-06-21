#include <bits/stdc++.h>
using namespace std;

auto solve(vector<string> s) -> decltype(s) {
  for(auto& si : s) for(auto& c : si) if(c == '.') c = ' ';
  for(auto it = s.rbegin(); it != s.rend() - 1; it++) {
    auto d = it->find_first_not_of(" |"); 
    (*it)[d - 1] = '+';
    for(auto jt = it + 1; jt != s.rend() && jt->find_first_not_of(" |") > d; jt++)
      (*jt)[d - 1] = '|';
  }
  return move(s);
}

auto main() -> int {
  int n;
  while(cin >> n, n) {
    vector<string> s(n);
    for(auto& si : s) cin >> si;
    for(const auto& si : solve(s)) cout << si << endl;
  }
  return 0;
}
