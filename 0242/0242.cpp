#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
  int n;
  char c, s[1024];
  while(cin >> n, n) {
    cin.ignore();
    map<string, int> words;
    for(int i = 0; i < n; i++) {
      cin.getline(s, sizeof(s));
      for(char* p = strtok(s, " "); p; p = strtok(nullptr, " ")) words[p]++;
    }
    cin >> c;
    vector<pair<int, string>> res;
    for(auto& x : words) if(x.first.front() == c) res.push_back(make_pair(-x.second, x.first));
    if(res.empty()) cout << "NA" << endl;
    else {
      sort(res.begin(), res.end());
      for(int i = 0; i < 5 && i < res.size(); i++) cout << (i ? " " : "") << res[i].second;
      cout << endl;
    }
  }
  return 0;
}
