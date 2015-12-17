#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x, y;
};
auto comp_x = [](const Point& lhs, const Point& rhs) {
  return lhs.x < rhs.x;
};
auto comp_y = [](const Point& lhs, const Point& rhs) {
  return lhs.y < rhs.y;
};
using VP = vector<Point>;

int closest_pair(VP::iterator begin, VP::iterator end) {
  if(end - begin <= 1) return INT_MAX;
  auto middle = begin + (end - begin) / 2;
  int x = (*middle).x;
  int d = min(closest_pair(begin, middle), closest_pair(middle, end));
  inplace_merge(begin, middle, end, comp_y);
  VP tmp;
  for(auto it = begin; it != end; it++) {
    if(abs((*it).x - x) >= d) continue;
    for(int i = tmp.size() - 1; i >= 0; i--) {
      int dx = (*it).x - tmp[i].x, dy = (*it).y - tmp[i].y;
      if(dy >= d) break;
      d = min(d, dx * dx + dy * dy);
    }
    tmp.push_back(*it);
  }
  return d;
}

int main() {
  int n;
  cin >> n;
  VP points(n);
  for(auto& point : points)
    cin >> point.x >> point.y;
  sort(points.begin(), points.end(), comp_x);
  cout << closest_pair(points.begin(), points.end()) << endl;
  return 0;
}
