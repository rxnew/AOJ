#include <iostream>
using namespace std;

int x, y, cnt;

void dfs(int cx, int cy, int dir, bool turnFlg) {
  if(cx == x && cy == y) {
    cnt++;
    return;
  }

  if(!turnFlg)
    if(x >= cx + (dir ^ 1) && y >= cy + dir)
      dfs(cx + (dir ^ 1), cy + dir, dir ^ 1, true);
  if(x >= cx + dir && y >= cy + (dir ^ 1))
    dfs(cx + dir, cy + (dir ^ 1), dir, false);
}

int main() {
  while(cin >> x >> y, x || y) {
    cnt = 0;
    dfs(1, 2, 0, false);
    dfs(2, 1, 1, false);
    cout << (cnt % 100000) << endl;
  }

  return 0;
}
