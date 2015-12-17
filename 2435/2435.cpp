#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <cctype>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define MP make_pair

using namespace std;

int calc(int a, int b, string& op) {
  if(op == "+") return a + b;
  if(op == "-") return a - b + 256;
  if(op == "*") return a * b;
  if(op == "/") return a / b;
}

vector<bool> getList(pair<int, int> n) {
  vector<bool> list(256, false);
  for(int i = n.first; i <= n.second; i++) list[i] = true;
  return list;
}

bool check(vector<string>& e, map<string, pair<int, int> >& vars) {
  stack<vector<bool> > s;
  REP(i, e.size()) {
    if(e[i].find_first_not_of("+-*/") == string::npos) {
      vector<bool> a, b, r(256, false);
      b = s.top(), s.pop();
      a = s.top(), s.pop();
      if(e[i] == "/" && b[0]) return false;
      REP(j, 256) if(a[j]) REP(k, 256) if(b[k]) r[calc(j, k, e[i]) % 256] = true;
      s.push(r);
    }
    else if(vars.find(e[i]) != vars.end())
      s.push(getList(vars[e[i]]));
    else
      s.push(getList(MP(stoi(e[i]), stoi(e[i]))));
  }
  return true;
}

int main() {
  int m, n;
  cin >> m;
  vector<string> name(m, string());
  vector<int> lb(m, 0), ub(m, 0);
  map<string, pair<int, int> > vars;
  REP(i, m) cin >> name[i] >> lb[i] >> ub[i], vars[name[i]] = MP(lb[i], ub[i]);
  cin >> n;
  vector<string> e(n, string());
  REP(i, n) cin >> e[i];
  cout << ((check(e, vars))? "correct": "error") << endl;
  return 0;
}
