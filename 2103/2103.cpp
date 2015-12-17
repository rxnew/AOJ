#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

char f[21][21];
int h, w, cx, cy;

int dir(int x, int y, char select) {
  int dx = 0, dy = 0;

  switch(f[y][x]) {
  case '^':
    dy = -1; break;
  case 'v':
    dy = 1; break;
  case '<':
    dx = -1; break;
  case '>':
    dx = 1; break;
  default:
    break;
  }

  if(select == 'x')
    return dx;
  else
    return dy;
}

bool inField(int x, int y) {
  if(x >= 0 && x < w && y >= 0 && y < h)
    return true;
  else
    return false;
}

void move(char op) {
  switch(op) {
  case 'U':
    f[cy][cx] = '^'; break;
  case 'D':
    f[cy][cx] = 'v'; break;
  case 'L':
    f[cy][cx] = '<'; break;
  case 'R':
    f[cy][cx] = '>'; break;
  default:
    break;
  }

  int nx = cx + dir(cx, cy, 'x'), ny = cy + dir(cx, cy, 'y');

  if(inField(nx, ny) && f[ny][nx] == '.') {
    swap(f[ny][nx], f[cy][cx]);
    cx = nx, cy = ny;
  }
}

void shoot() {
  int dx = dir(cx, cy, 'x'), dy = dir(cx, cy, 'y');
  
  for(int i = 1; inField(cx + dx * i, cy + dy * i); i++) {
    if(f[cy + dy * i][cx + dx * i] == '*') {
      f[cy + dy * i][cx + dx * i] = '.';
      break;
    }
    else if(f[cy + dy * i][cx + dx * i] == '#')
      break;
  }
}

int main() {
  int t, n;
  char op[101];
  char ans[101][21][21] = {0};

  cin >> t;

  REP(cnt, t) {
    cin >> h >> w;
    REP(i, h) {
      cin >> f[i];
      REP(j, w)
	if(f[i][j] == '^' || f[i][j] == 'v' || f[i][j] == '<' || f[i][j] == '>')
	  cx = j, cy = i;
    }
    cin >> n >> op;
    REP(i, n) {
      if(op[i] == 'S')
	shoot();
      else
	move(op[i]);
    }
    
    REP(i, h) {
      REP(j, w)
	ans[cnt][i][j] = f[i][j];
    }
  }

  REP(cnt, t) {
    if(cnt)
      cout << endl;
    for(int i = 0; ans[cnt][i][0]; i++)
	cout << ans[cnt][i] << endl;
  }

  return 0;
}
