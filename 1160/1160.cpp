#include <iostream>
#include <queue>
#include <map>
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
using namespace std;

const int dw[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dh[] = {1, 1, 0, -1, -1, -1, 0, 1};
int w, h, area[1000][1000];

typedef pair<int, int> crd;

void bfs(crd cur){
  queue<crd> que;

  que.push(cur);
  area[cur.second][cur.first] = 0;
  
  while(que.size()) {
    cur = que.front();
    que.pop();
    
    REP(i, 8) {
      int nw = cur.first + dw[i];
      int nh = cur.second + dh[i];
      if(nw >= 0 && nw < w && nh >= 0 && nh < h && area[nh][nw] == 1) {
	que.push(MP(nw, nh));
	area[nh][nw] = 0;
      }
    }
  }
}

int main() {
  while(cin >> w >> h, w || h) {
    int cnt = 0;

    REP(i, h) REP(j, w)
      cin >> area[i][j];

    REP(i, h) REP(j, w)
      if(area[i][j])
	bfs(MP(j, i)), cnt++;

    cout << cnt << endl;
  }

  return 0;
}
