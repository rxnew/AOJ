// Minimum spanning tree
// Prim's algorithm

#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x, y, z, r;
  auto operator-(const Point& other) const -> double {
    auto d = sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2)) - r - other.r;
    return d >= 0.0 ? d : 0.0;
  }
};

auto prim(int n, const vector<Point>& cells) -> double {
  vector<bool> used(n, false);
  vector<double> mincost(n, numeric_limits<double>::max());
  double result = 0.0;
  int p = 0;
  used[p] = true;
  while(true) {
    int q = 0;
    for(int i = 1; i < n; i++) if(!used[i] && (mincost[i] = min(mincost[i], cells[p] - cells[i])) < mincost[q]) q = i;
    if(!(p = q)) break;
    used[p] = true;
    result += mincost[p];
  }
  return result;
}

auto main() -> int {
  int n;
  while(cin >> n, n) {
    vector<Point> cells(n);
    for(auto& cell : cells) cin >> cell.x >> cell.y >> cell.z >> cell.r;
    cout << fixed << setprecision(3) << prim(n, cells) << endl;
  }
  return 0;
}
