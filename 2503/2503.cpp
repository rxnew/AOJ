#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

class Tsort {
 private:
  vector<vector<int> > g_;
  vector<int> l_;
  vector<bool> visit_;
 public:
  Tsort(vector<vector<int> >& g): g_(g), visit_(vector<bool>(g.size(), false)) {
    sort(0), reverse(l_.begin(), l_.end());
  }
  void sort(int v) {
    visit_[v] = true;
    REP(i, g_.size()) if(g_[v][i] > 0 && !visit_[i]) sort(i);
    l_.push_back(v);
  }
  inline const vector<int>& sorted() {return l_;}
};

int solve(vector<vector<int> >& g) {
  vector<int> dp(g.size(), 0);
  vector<int> l = Tsort(g).sorted();
  FOR(i, 1, l.size()) REP(j, l.size())
    if(g[l[j]][l[i]] > 0) dp[l[i]] = max(dp[l[i]], dp[l[j]] + g[l[j]][l[i]]);
  return dp.back();
}

int main() {
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int> > g(n, vector<int>(n, 0));
  REP(i, m) cin >> a >> b, cin >> g[a][b];
  cout << solve(g) << endl;
  return 0;
}
