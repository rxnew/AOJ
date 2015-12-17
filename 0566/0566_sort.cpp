#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)
using namespace std;

const int wp = 3, dp = 1;

int main() {
  int n, ta, tb, pa, pb;
  vector<pair<int, int> > p, tmp;

  cin >> n;
  REP(i, n)
    p.PB(MP(0, i));

  REP(i, n * (n - 1) / 2) {
    cin >> ta >> tb >> pa >> pb;
    if(pa == pb)
      p[ta - 1].first += dp, p[tb - 1].first += dp;
    else if(pa > pb)
      p[ta - 1].first += wp;
    else
      p[tb - 1].first += wp;
  }

  tmp = p;
  sort(tmp.begin(), tmp.end(), greater<pair<int, int> >());
  
  for(int i = 0; i < n;) {
    int j = i + 1;
    do {
      p[tmp[i].second].first = j;
      i++;
    } while(tmp[i - 1].first == tmp[i].first);
  }

  REP(i, n)
    cout << p[i].first << endl;

  return 0;
}
