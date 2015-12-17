#include <iostream>
using namespace std;

int main() {
  int line[100][1000];
  int n, m, a, h, p, q, row;

  while(cin >> n >> m >> a, (n || m || a)) {
    row = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++)
	line[i][j] = 0;
    }

    for(int i = 0; i < m; i++) {
      cin >> h >> p >> q;
      line[p - 1][h - 1] = q;
      line[q - 1][h - 1] = p;
      if(row < h)
	row = h;
    }

    for(int i = row - 1; i >= 0; i--) {
      if(line[a - 1][i] != 0)
	a = line[a - 1][i];
    }

    cout << a << endl;
  }

  return 0;
}
