#include <iostream>
#include <vector>
#include <queue>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define PB push_back
#define MP make_pair
#define INF (1 << 21)

using namespace std;

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

struct P {
  int x, y;
  P(int a, int b) {x = a, y = b;}
  bool operator==(const P& t) {return x == t.x && y == t.y;}
};

int bfs(vector<string> s, int h, int w, P a, P b) {
  int x, y, d[h][w];
  queue<P> q;
  q.push(a), d[a.y][a.x] = 0;
  s[a.y][a.x] = 'x';
  while(!q.empty()) {
    P cur = q.front(); q.pop();
    REP(i, 4) {
      x = cur.x + dx[i], y = cur.y + dy[i];
      if(x >= 0 && y >= 0 && x < w && y < h && s[y][x] != 'x') {
        d[y][x] = d[cur.y][cur.x] + 1;
        if(x == b.x && y == b.y) return d[y][x];
        q.push(P(x, y));
        s[y][x] = 'x';
      }
    }
  }
  return INF;
}

int tsp(vector<vector<int> >& d, int n, int h, int w) {
  int res = INF;
  int dp[1 << n][n];
  fill((int*)dp, (int*)(dp + (1 << n)), INF);
  REP(i, n) dp[1 << i][i] = d[n][i];
  REP(i, 1 << n) REP(j, n) REP(k, n)
    dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + d[j][k]);
  REP(i, n) res = min(res, dp[(1 << n) - 1][i]);
  return res < INF ? res : -1;
}

int main() {
  int w, h;
  while(cin >> w >> h, w || h) {
    vector<string> s(h);
    vector<P> pos;
    P a(0, 0);
    REP(i, h) {
      cin >> s[i];
      REP(j, w) {
        if(s[i][j] == '*') pos.PB(P(j, i));
        if(s[i][j] == 'o') a = P(j, i);
      }
    }
    int n = pos.size();
    vector<vector<int> > d(n + 1, vector<int>(n));
    vector<int> t;
    REP(i, n) REP(j, n)
      d[i][j] = bfs(s, h, w, pos[i], pos[j]);
    REP(i, n) d[n][i] = bfs(s, h, w, a, pos[i]);
    cout << tsp(d, n, h, w) << endl;
  }
  return 0;
}
