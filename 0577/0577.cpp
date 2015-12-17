#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, card[201][3], exist[3][101] = {0}, sum[201] = {0};

  cin >> n;
  REP(i, n) REP(j, 3)
    cin >> card[i][j], exist[j][card[i][j]]++;

  REP(i, n) REP(j, 3)
    if(exist[j][card[i][j]] == 1)
      sum[i] += card[i][j];

  REP(i, n)
    cout << sum[i] << endl;

  return 0;
}
