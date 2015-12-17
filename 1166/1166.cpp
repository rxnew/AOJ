#include <iostream>
#include <queue>
#include <map>
#include <climits>
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
using namespace std;

typedef pair<int, int> P;
typedef vector<int> Vi;

const int P::* x = &P::first;
const int P::* y = &P::second;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int w, h;

int bfs(vector<vector<Vi> > f) {
  int nx, ny, dist[h][w];
  queue<P> que;
  P cur;

  REP(i, h) REP(j, w)
    dist[i][j] = ((!i && !j)? 0: INT_MAX);
  que.push(cur = MP(0, 0));
  while(que.size()) {
    cur = que.front(), que.pop();
    REP(i, 4)
      if((nx = cur.*x + dx[i]) >= 0 && (ny = cur.*y + dy[i]) >= 0)
	if(nx < w && ny < h && !f[cur.*y][cur.*x][i] && dist[ny][nx] > dist[cur.*y][cur.*x] + 1)
	  que.push(MP(nx, ny)), dist[ny][nx] = dist[cur.*y][cur.*x] + 1;
  }
  
  return ((dist[h - 1][w - 1] != INT_MAX)? dist[h - 1][w - 1] + 1: 0);
}

int main() {
  int ini;

  while(cin >> w >> h, w || h) {
    vector<vector<Vi> > f(h + 1, vector<Vi>(w + 1, Vi(4, 0)));

    REP(i, h) REP(k, ((i < h - 1)? 2: 1)) REP(j, w - 1 + k)
      cin >> ini, f[i][j][k] = f[i + ((k)? 1: 0)][j + ((k)? 0: 1)][k + 2] = ini;

    cout << bfs(f) << endl;
  }

  return 0;
}
