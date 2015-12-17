#include <iostream>
#include <stack>
#define MAX_A 16
#define MAX_B 16
using namespace std;

typedef struct {
  int x, y;
} node;

bool field[MAX_A + 1][MAX_B + 1];
int gx, gy;
stack<node> s;

node makeNode(int x, int y) {
  node node;
  node.x = x, node.y = y;
  return node;
}

int dfs(int cnt) {
  node cur = s.top();
  s.pop();

  if(cur.x == gx && cur.y == gy) {
    return cnt + 1;
  }
  if(field[cur.x + 1][cur.y]) {
    s.push(makeNode(cur.x + 1, cur.y));
    cnt = dfs(cnt);
  }
  if(field[cur.x][cur.y + 1]) {
    s.push(makeNode(cur.x, cur.y + 1));
    cnt = dfs(cnt);
  }

  return cnt;
}

int main() {
  int a, b, n, x, y;

  while(cin >> a >> b, a || b) {
    gx = a - 1, gy = b - 1;
    for(int i = 0; i < a; i++) {
      for(int j = 0; j < b; j++)
	field[i][j] = true;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> x >> y;
      field[x - 1][y - 1] = false;
    }

    s.push(makeNode(0, 0));
    cout << dfs(0) << endl;
  }

  return 0;
}
