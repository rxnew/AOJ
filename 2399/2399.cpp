#include <iostream>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)n; i++)

using namespace std;

int search(vector<vector<bool> >& p, vector<int>& l) {
  int result = -1;
  REP(i, p.size()) {
    bool flg = true;
    REP(j, l.size()) flg &= p[i][l[j] - 1];
    if(!flg) continue;
    if(result == -1) result = i + 1;
    else return -1;
  }
  return result;
}

int main() {
  int n, m, k, pi;
  while(cin >> n, n) {
    vector<vector<bool> > p(n, vector<bool>(n, false));
    REP(i, n) {
      cin >> m;
      REP(j, m) cin >> pi, p[i][pi - 1] = true;
    }
    cin >> k;
    vector<int> l(k, 0);
    REP(i, k) cin >> l[i];
    cout << search(p, l) << endl;
  }
  return 0;
}
