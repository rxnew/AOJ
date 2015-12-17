#include <iostream>
#include <vector>
#include <queue>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define PB push_back
#define MP make_pair

using namespace std;

const int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
vector<string> field;
vector<vector<int> > release;

int bfs(int w, int h, int n, int x[], int y[]) {
  int s = 0;
  vector<bool> wait(n + 1, false);
  queue<pair<int, int> > que;
  que.push(MP(0, 0));
  field[0][0] = '*';
  do {
    while(!que.empty()) {
      pair<int, int> cur = que.front();
      que.pop();
      REP(i, 4) {
        int nx = cur.first + dx[i], ny = cur.second + dy[i];
        if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
        if(field[ny][nx] == 't') return s;
        if(field[ny][nx] == '*') continue;
        if(field[ny][nx] == '#') wait[release[ny][nx]] = true;
        else que.push(MP(nx, ny)), field[ny][nx] = '*';
      }
    }
    for(s++; s <= n; s++) {
      if(wait[s]) {
        que.push(MP(x[s], y[s]));
        field[y[s]][x[s]] = '*';
        break;
      }
      field[y[s]][x[s]] = '.';
    }
  } while(s <= n);
  return -1;
}

int main() {
  int w, h, n;
  cin >> w >> h;
  field.assign(h, string());
  release.assign(h, vector<int>(w, 0));
  REP(i, h) cin >> field[i];
  cin >> n;
  int x[n + 1], y[n + 1];
  for(int i = 1; i <= n; i++) cin >> x[i] >> y[i], release[y[i]][x[i]] = i;
  cout << bfs(w, h, n, x, y) << endl;
}
