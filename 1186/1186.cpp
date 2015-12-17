#include <iostream>
#include <set>
#define FOR(i, a, n) for(int i = a; i < n; i++)
using namespace std;

class Rectangle {
 public:
  int h, w, d;
  Rectangle(int h, int w): h(h), w(w), d(h * h + w * w) {}
  bool operator<(const Rectangle& other) const {
    return d < other.d | (d == other.d && h < other.h);
  }
  bool operator==(const Rectangle& other) const {
    return h == other.h & w == other.w;
  }
};

int main() {
  int h, w;
  set<Rectangle> s;
  FOR(i, 1, 150) FOR(j, i + 1, 150) s.insert(Rectangle(i, j));
  while(cin >> h >> w, h || w) {
    auto f = ++s.find(Rectangle(h, w));
    cout << f->h << ' ' << f->w << endl;
  }
  return 0;
}
