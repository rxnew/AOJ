#include <iostream>
#include <queue>
#include <map>
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
using namespace std;

typedef pair<int, int> crd;

const int crd::* x = &crd::first;
const int crd::* y = &crd::second;
const int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};

map<char, int> sum;
int w, h;
char a[51][51];

void bfs(crd cur) {
  queue<crd> q;
  int cnt = 0;
  char color = 'G';
  bool flg = true;

  q.push(cur);
  a[cur.*y][cur.*x] = '*';
  while(q.size()) {
    cur = q.front(), q.pop();
    cnt++;
    REP(i, 4) {
      int nx = cur.*x + dx[i], ny = cur.*y + dy[i];
      if(nx >= 0 && nx < w && ny >= 0 && ny < h) {
	if(a[ny][nx] == '.')
	  q.push(MP(nx, ny)), a[ny][nx] = '*';
	else if(a[ny][nx] == 'B' || a[ny][nx] == 'W') {
	  if(color == 'G')
	    color = a[ny][nx];
	  else if(color != a[ny][nx])
	    flg = false;
	}
      }
    }
  }
  
  if(flg)
    sum[color] += cnt;
}

int main() {
  sum.insert(MP('B', 0)), sum.insert(MP('W', 0));

  while(cin >> w >> h, w || h) {
    REP(i, h)
      cin >> a[i];

    sum['B'] = 0, sum['W'] = 0;
    REP(i, h) REP(j, w)
      if(a[i][j] == '.')
	bfs(MP(j, i));

    cout << sum['B'] << ' ' << sum['W'] << endl;
  }

  return 0;
}
