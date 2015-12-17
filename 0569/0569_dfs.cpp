#include <iostream>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int st[102][102] = {0};
int w, h, res = 0;
const int dx[][6] = {{1, -1, 0, 0, -1, -1}, {1, -1, 0, 0, 1, 1}}, dy[] = {0, 0, 1, -1, 1, -1};

void dfs(int x, int y) {
  st[x][y] = -1;
  REP(i, 6) {
    int nx = x + dx[y % 2][i], ny = y + dy[i];
    if(nx >= 0 && nx <= w + 1 && ny >= 0 && ny <= h + 1) {
      if(st[nx][ny] == 1)
	res++;
      else if(st[nx][ny] == 0)
	dfs(nx, ny);
    }
  }
}

int main() {
  cin >> w >> h;
  REP(i, h) REP(j, w)
    cin >> st[j + 1][i + 1];
  
  dfs(0, 0);

  cout << res << endl;

  return 0;
}
