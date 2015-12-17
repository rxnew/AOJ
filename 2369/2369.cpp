#include <iostream>
#include <vector>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

bool isCat(string& s) {
  if(s[0] != 'm') return false;
  vector<int> v(1, 0);
  FOR(i, 1, s.size()) {
    if(v.empty()) return false;
    if(s[i] == 'm') v.push_back(0);
    else if(s[i] == 'e') {
      if(v.back() != 0) return false;
      v.back()++;
    }
    else if(s[i] == 'w') {
      if(v.back() != 1) return false;
      v.pop_back();
    }
  }
  return v.empty()? true: false;
}

int main() {
  string s;
  cin >> s;
  cout << (isCat(s)? "Cat": "Rabbit") << endl;
  return 0;
}
