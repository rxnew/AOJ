#include <iostream>
#include <string>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

int solve(string&& s) {
  int res = 0;
  REP(i, s.size()) {
    if(s[i] == '0') continue;
    int a1 = ((i)? stoi(s.substr(0, i)): 0), a2 = stoi(s.substr(i));
    if(a1 > a2) break;
    if(a1 % 2 == a2 % 2) res++;
  }
  return res;
}

int main() {
  int a;
  cin >> a;
  cout << solve(to_string(a)) << endl;
  return 0;
}
