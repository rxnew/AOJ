#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <climits>
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define PB push_back
using namespace std;

int main() {
  int w, n, vi, wi;

  for(int cnt = 1; cin >> w, w; cnt++) {
    cin >> n;

    vector<pair<int, int> > tr;
    vector<vector<int> > dp(n + 1, vector<int>(w + 1, 0));
    int maxv = 0, maxw = INT_MAX;

    REP(i, n) {
      scanf("%d,%d", &vi, &wi);
      tr.PB(MP(vi, wi));
    }
    
    REP(i, n) {
      REP(j, w + 1) {
	if(j >= tr[i].second)
	  dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - tr[i].second] + tr[i].first);
	dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      }
    }

    REP(i, w + 1) {
      if(maxv <= dp[n][i]) {
	maxw = (maxv == dp[n][i])? min(maxw, i): i;
	maxv = dp[n][i];
      }
    }

    cout << "Case " << cnt << ":" << endl << maxv << endl << maxw << endl;
  }

  return 0;
}
