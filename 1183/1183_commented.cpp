#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define PB push_back
#define INF 1 << 15
using namespace std;

typedef struct {double x, y;} coord;

class Chain {
 public:
  int n;
  vector<coord> c;
  vector<double> r;
  vector<vector<double> > adj;

  Chain(vector<coord>& c, vector<double>& r, int n): c(c), r(r), n(n) {}

  /* 二つの線分の公差判定 */ 
  bool isIntersect(vector<coord> a, vector<coord> b) {
    double ta[] = {(b[0].x - b[1].x) * (a[0].y - b[0].y) +
                   (b[0].y - b[1].y) * (b[0].x - a[0].x),
                   (b[0].x - b[1].x) * (a[1].y - b[0].y) +
                   (b[0].y - b[1].y) * (b[0].x - a[1].x)};
    double tb[] = {(a[0].x - a[1].x) * (b[0].y - a[0].y) +
                   (a[0].y - a[1].y) * (a[0].x - b[0].x),
                   (a[0].x - a[1].x) * (b[1].y - a[0].y) +
                   (a[0].y - a[1].y) * (a[0].x - b[1].x)};
    return ta[0] * ta[1] < 0 & tb[0] * tb[1] < 0;
  }

  /* 線分が円の内側に存在しているか判定 */
  bool isConfined(vector<coord> a, vector<vector<coord> >& inter, int i, int j) {
    FOR(m, i + 1, j) 
      if(!isIntersect(a, {inter[m][0], inter[m][1]}))
        return false;
    return true;
  }

  /* 二つの円の交点を取得 */
  vector<coord> getIntersection(vector<coord> c, vector<double> r) {
    vector<coord> res(2);
    double x = c[1].x - c[0].x, y = c[1].y - c[0].y;
    double a = pow(x, 2) + pow(y, 2);
    double b = (a + pow(r[0], 2) - pow(r[1], 2)) / 2;
    double e = sqrt(a * pow(r[0], 2) - pow(b, 2));
    res[0].x = (b * x + y * e) / a + c[0].x;
    res[0].y = (b * y - x * e) / a + c[0].y;
    res[1].x = (b * x - y * e) / a + c[0].x;
    res[1].y = (b * y + x * e) / a + c[0].y;
    return res;
  }

  /* 隣り合う円の交点リストを取得 */
  vector<vector<coord> > getIntersection() {
    vector<vector<coord> > res;
    REP(i, n - 1)
      res.PB(getIntersection({c[i], c[i + 1]}, {r[i], r[i + 1]}));
    return res;
  }

  /* パスの候補を隣接リストとして取得 */
  vector<vector<double> > getAdjacencyList() {
    vector<vector<double> > res(n * 2, vector<double>(n * 2, INF));
    vector<vector<coord> > inter = getIntersection();
    /* 各交点を結ぶ線分 */
    REP(i, n - 2) FOR(j, i + 1, n - 1) REP(k, 2) REP(l, 2)
      if(isConfined({inter[i][k], inter[j][l]}, inter, i, j))
        res[i * 2 + k][j * 2 + l]
          = sqrt(pow(inter[i][k].x - inter[j][l].x, 2) +
                 pow(inter[i][k].y - inter[j][l].y, 2));
    /* 始点と各交点を結ぶ線分 */
    REP(i, n - 1) REP(j, 2)
      if(isConfined({c[0], inter[i][j]}, inter, -1, i))
        res[n * 2 - 2][i * 2 + j]
          = sqrt(pow(c[0].x - inter[i][j].x, 2) +
                 pow(c[0].y - inter[i][j].y, 2));
    /* 終点と各交点を結ぶ線分 */
    REP(i, n - 1) REP(j, 2)
      if(isConfined({inter[i][j], c[n - 1]}, inter, i, n - 1))
        res[i * 2 + j][n * 2 - 1]
          = sqrt(pow(inter[i][j].x - c[n - 1].x, 2) +
                 pow(inter[i][j].y - c[n - 1].y, 2));
    /* 始点と終点を結ぶ線分 */
    if(isConfined({c[0], c[n - 1]}, inter, -1, n - 1))
      res[n * 2 - 2][n * 2 - 1]
        = sqrt(pow(c[0].x - c[n - 1].x, 2) +
               pow(c[0].y - c[n - 1].y, 2));
    return res;
  }
};

/* ダイクストラ法 */
double dijkstra(vector<vector<double> > adj, int n) {
  vector<bool> close(n, false);
  vector<double> dist(n, INF);
  int cur = n - 2;
  close[cur] = true, dist[cur] = 0;
  while(!close[n - 1]) {
    int next = n - 1;
    REP(i, n) {
      if(!close[i]) {
        dist[i] = min(dist[i], dist[cur] + adj[cur][i]);
        if(dist[i] < dist[next]) next = i;
      }
    }
    close[next] = true, cur = next;
  }
  return dist[n - 1];
}

int main() {
  int n;
  while(cin >> n, n) {
    vector<coord> c(n); vector<double> r(n);
    REP(i, n) cin >> c[i].x >> c[i].y >> r[i];
    cout << fixed << setprecision(6)
         << dijkstra(Chain(c, r, n).getAdjacencyList(), n * 2)
         << endl;
  }
  return 0;
}
