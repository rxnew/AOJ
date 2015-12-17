#include <iostream>
using namespace std;

char field[9][9];
int vx[4] = {-1, 0, 1, 0};
int vy[4] = {0, -1, 0, 1};

void Bomb(int x, int y) {
  int nx, ny;

  field[y][x] = '0';

  for(int i = 1; i <= 3; i++) {
    for(int j = 0; j < 4; j++) {
      nx = x + vx[j] * i, ny = y + vy[j] * i;
      if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && field[ny][nx] == '1')
	Bomb(nx, ny);
    }
  }
}

int main() {
  int n, sx, sy;
  
  cin >> n;
  for(int data = 0; data < n; data++) {
    for(int i = 0; i < 8; i++)
      cin >> field[i];

    cin >> sx >> sy;

    Bomb(sx - 1, sy - 1);

    cout << "Data " << data + 1 << ":" << endl;

    for(int i = 0; i < 8; i++)
      cout << field[i] << endl;
  }

  return 0;
}
