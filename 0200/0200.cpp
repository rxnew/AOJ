#include <iostream>
#include <queue>
#include <map>
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define INF -1
using namespace std;

typedef pair<int, int> P;

int main() {
  int n, m, a, b, k, p, q, r, cost, time, ans, tmp;
  P cur;

  while(cin >> n >> m, n || m) {
    int edge[m][m][2];
    
    REP(i, m) REP(j, m) REP(k, 2)
      edge[i][j][k] = INF;

    REP(i, n) {
      cin >> a >> b >> cost >> time;
      a--, b--;
      edge[a][b][0] = cost, edge[a][b][1] = time;
      edge[b][a][0] = cost, edge[b][a][1] = time;
    }

    cin >> k;

    while(k--) {
      priority_queue<P, vector<P>, greater<P> > que;
      bool reach[m];

      cin >> p >> q >> r;
      p--, q--;

      REP(i, m)
	reach[i] = false;

      que.push(MP(0, p));
      
      while(que.size()) {
	cur = que.top(), que.pop();

	if(cur.second == q) {
	  ans = cur.first;
	  break;
	}
	
	reach[cur.second] = true;
	
	REP(i, m)
	  if(!reach[i] && (tmp = edge[cur.second][i][r]) != INF)
	    que.push(MP(cur.first + tmp, i));
      }

      cout << ans << endl;
    }
  }
    
  return 0;
}
