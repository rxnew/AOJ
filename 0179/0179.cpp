#include <bits/stdc++.h>
using namespace std;

auto is(string const& s) -> bool {
  auto c = s.front();
  for(auto const& ci : s) {
    if(ci != c) return false;
  }
  return true;
}

auto get(char l, char r) -> char {
  if(l == 'r' && r == 'g') return 'b';
  if(r == 'r' && l == 'g') return 'b';
  if(l == 'r' && r == 'b') return 'g';
  if(r == 'r' && l == 'b') return 'g';
  if(l == 'b' && r == 'g') return 'r';
  if(r == 'b' && l == 'g') return 'r';
}

auto change(char& l, char& r) -> void {
  auto c = get(l, r);
  l = c, r = c;
}

auto bfs(string const& s) -> int {
  unordered_set<string> close;
  queue<pair<string, int>> q;
  q.push(make_pair(s, 0));
  close.insert(s);
  while(!q.empty()) {
    auto st = q.front().first;
    auto t = q.front().second;
    q.pop();
    if(is(st)) return t;
    for(auto i = 1u; i < s.size(); ++i) {
      auto stt = st;
      if(stt[i - 1] != stt[i]) change(stt[i - 1], stt[i]);
      if(close.count(stt)) continue;
      q.push(make_pair(stt, t + 1));
      close.insert(stt);
    }
  }
  return -1;
}

auto main() -> int {
  string s;
  while(cin >> s, s.front() != '0') {
    auto t = bfs(s);
    if(t != -1) cout << t << endl;
    else        cout << "NA" << endl;
  }
  return 0;
}
