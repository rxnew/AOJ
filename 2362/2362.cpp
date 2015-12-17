#include <iostream>
#include <vector>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define PB push_back

using namespace std;

const string a[2] = {"egg", "chicken"};

int main() {
  string s;
  vector<vector<string> > t(1);
  int pos, m = 0;
  cin >> s;
  int i = (s[0] == 'e' ? 0 : 1);
  for( ; ; i = ++i % 2) {
    if(s.empty()) break;
    if(s[0] == a[i][0]) {
      t.back().PB(s.substr(0, a[i].size()));
      s.erase(pos, a[i].size());
    }
    else t.PB(vector<string>());
  }
  REP(i, t.size()) if(t[m].size() < t[i].size()) m = i;
  cout << t[m].back() << endl;
  return 0;
}
