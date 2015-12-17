#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, ans_len;
  getline(cin, s);
  map<string, int> m;
  int current = 0, found, len = 0;
  auto f = [&](){
    string t = string(s, current, found - current);
    m.find(t) != m.end() ? m[t]++ : m[t] = 1;
    current = found + 1;
    if(t.length() > len) len = t.length(), ans_len = t;
  };
  while((found = s.find_first_of(' ', current)) != string::npos) f();
  f();
  vector<pair<int, string>> ans_num;
  for(auto var : m) ans_num.push_back(make_pair(var.second, var.first));
  sort(ans_num.begin(), ans_num.end(), greater<pair<int, string>>());
  cout << ans_num.front().second << ' ' << ans_len << endl;
  return 0;
}
