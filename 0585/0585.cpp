#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Point {
  ll x, y;
};

auto comp_x = [](const Point& lhs, const Point& rhs) {
  return lhs.x < rhs.x;
};

auto comp_y = [](const Point& lhs, const Point& rhs) {
  return lhs.y < rhs.y;
};

ll findClosestPair(vector<Point>& points) {
  if(points.size() <= 1) return LLONG_MAX >> 1;
  auto m_itr = points.begin() + (points.size() >> 1);
  ll x = (*m_itr).x;
  vector<Point> points_l(points.begin(), m_itr);
  vector<Point> points_r(m_itr, points.end());
  ll d = min(findClosestPair(points_l), findClosestPair(points_r));
  sort(points.begin(), points.end(), comp_y);

  vector<Point> tmp;
  for(const auto& point : points) {
    if(llabs(point.x - x) >= d) continue;
    for(int i = tmp.size() - 1; i >= 0; i--) {
      ll dx = point.x - tmp[i].x;
      ll dy = point.y - tmp[i].y;
      if(dy >= d) break;
      d = min(d, dx * dx + dy * dy);
    }
    tmp.push_back(point);
  }
  return d;
}

int main() {
  int n;
  cin >> n;
  vector<Point> points(n);
  for(auto& point : points)
    cin >> point.x >> point.y;
  sort(points.begin(), points.end(), comp_x);
  cout << findClosestPair(points) << endl;
  return 0;
}
