#include <bits/stdc++.h>
using namespace std;

struct P {
  int w, d;
  auto area() const -> int {return w * d;}
  auto operator<(const P& obj) const -> bool {return area() < obj.area();}
  auto cut(int s) const -> list<P> {
    P p1, p2;
    auto r = s % (w + d);
    if(r < w) p1 = {r, d},     p2 = {w - r, d};
    else      p1 = {w, r - w}, p2 = {w, d - r + w};
    return p1 < p2 ? list<P>{p1, p2} : list<P>{p2, p1};
  }
};

auto main() -> int {
  int n, w, d, pi, si;
  while(cin >> n >> w >> d, n || w || d) {
    list<P> pieces{P{w, d}};
    for(auto i = 0; i < n; i++) {
      cin >> pi >> si;
      auto it = pieces.begin();
      for(auto j = 1; j < pi; j++) it++;
      auto p = *it;
      pieces.erase(it);
      pieces.splice(pieces.cend(), p.cut(si));
    }
    pieces.sort();
    int c = 0;
    for(const auto& p : pieces) cout << p.area() << (c++ < n ? ' ' : '\n');
  }
  return 0;
}
