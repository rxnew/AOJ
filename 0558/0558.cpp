#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_H = 1000;
const int MAX_W = 1000;
const int MAX_N = 10;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

typedef struct {
	int x, y;
} node;
node makeNode(int x, int y) {
	node n = {x, y};
	return n;
}

int w, h, n;

char field[MAX_H][MAX_W];
int step[MAX_H][MAX_W];

int bfs(int startX, int startY, int goalX, int goalY) {
  queue<node> que;
  node node;

  que.push(makeNode(startX, startY));
  step[startY][startX] = 0;

  while(que.size()) {
    node = que.front();
    que.pop();
    if(node.x == goalX && node.y == goalY) break;

    for(int i = 0; i < 4; i++) {
      int nx = node.x + dx[i];
      int ny = node.y + dy[i];

      if(0 <= nx && nx < w && 0 <= ny && ny < h && field[ny][nx] != 'X' && step[ny][nx] == -1) {
	que.push(makeNode(nx, ny));
	step[ny][nx] = step[node.y][node.x] + 1;
      }
    }
  }

  return step[goalY][goalX];
}

int main () {
  int startX[10], startY[10];
  cin >> h >> w >> n;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> field[i][j];
      if (field[i][j] == 'S') {
	startX[0] = j;
	startY[0] = i;
      }
      else if (isdigit(field[i][j])) {
	startX[field[i][j] - '0'] = j;
	startY[field[i][j] - '0'] = i;
      }
    }
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    memset(step, -1, sizeof(step));
    ans += bfs(startX[i], startY[i], startX[i + 1], startY[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
