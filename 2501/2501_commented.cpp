#include <iostream>
#include <stdlib.h>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define INF 999999
using namespace std;

typedef struct {
  int h, w;
} coord;

/* 順番から座標を返す関数 */
coord checkCoord(int n, int stride) {
  coord crd;
  crd.h = n / stride, crd.w = n % stride;
  return crd;
}

int main() {
  int n, abcd[4];
  int min_dist = INF;
  coord crd[4];

  /* 入力 */
  cin >> n;
  REP(i, 4)
    cin >> abcd[i];

  /* 幅1からnまでループ */
  FOR(stride, 1, n + 1) {
    int grid[n];
    int dist = 0;
    /* 各建物の座標を取得 */
    REP(i, 4)
      crd[i] = checkCoord(abcd[i] - 1, stride);
    /* 距離の和を計算 */
    for(int i = 0; i <= 2; i += 2)
      dist += abs(crd[i].h - crd[i + 1].h) + abs(crd[i].w - crd[i + 1].w);
    /* 最少距離を更新 */
    min_dist = min(dist, min_dist);
  }

  cout << min_dist << endl;
  
  return 0;
}
