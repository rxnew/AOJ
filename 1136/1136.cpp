#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define REVERSE(v) reverse((v).begin(), (v).end())
#define PB push_back
#define MP make_pair

using namespace std;

int f(vector<int>& a, vector<int>& b, int n) {
  return a[n] - a[n + 1] + b[n] - b[n + 1];
}

vector<int> getLength(vector<int>& x, vector<int>& y) {
  vector<int> res;
  REP(i, x.size() - 1) res.PB(abs(f(x, y, i)));
  return res;
}

vector<int> getAngle(vector<int>& x, vector<int>& y) {
  vector<int> res;
  FOR(i, 1, x.size() - 1) {
    res.PB(x[i - 1] - x[i] ? 1 : -1);
    if((f(x, y, i - 1) < 0) ^ (f(x, y, i) < 0)) res.back() *= -1;
  }
  return res;
}

int main() {
  int n, m, x, y;
  while(cin >> n, n) {
    int ans = 0;
    pair<vector<int>, vector<int> > s[2];
    REP(i, n + 1) {
      cin >> m;
      vector<int> x(m), y(m);
      REP(j, m) cin >> x[j] >> y[j];
      auto t = MP(getLength(x, y), getAngle(x, y));
      if(i == 0) {
        REVERSE(x), REVERSE(y);
        s[0] = t, s[1] = MP(getLength(x, y), getAngle(x, y));
      }
      else if(s[0] == t || s[1] == t) cout << i << endl;
    }
    cout << "+++++" << endl;
  }
  return 0;
}
