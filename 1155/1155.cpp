#include <iostream>
#include <unordered_map>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

unordered_map<char, int> term = {{'0', 0}, {'1', 1}, {'2', 2}};
string::iterator it;

int formula() {
  if(*it == '(') {
    it++;
    int f = formula();
    if(*it == '*') ++it, f = min(f, formula());
    if(*it == '+') ++it, f = max(f, formula());
    return ++it, f;
  }
  else if(*it == '-') return ++it, 2 - formula();
  else return term[*(it++)];
  return 0;
}

int main() {
  string s;
  while(cin >> s, s[0] != '.') {
    int cnt = 0;
    REP(i, 3) REP(j, 3) REP(k, 3)
      it = s.begin(),
      term['P'] = i, term['Q'] = j, term['R'] = k,
      cnt += (formula() == 2? 1: 0);
    cout << cnt << endl;
  }
  return 0;
}
