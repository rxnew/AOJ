#include <iostream>
#include <cmath>
 
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
 
using namespace std;
 
int main() {
  int time[3][2][3], tmp[3][2] = {0};
   
  REP(i, 3) REP(j, 2) REP(k, 3)
    cin >> time[i][j][k];
 
  REP(i, 3) REP(j, 2) REP (k, 3)
    tmp[i][j] += time[i][j][k] * pow(60, abs(k - 2));
   
  REP(i, 3)
    tmp[i][1] -= tmp[i][0];
 
  REP(i, 3) {
    REP(k, 3) {
      time[i][0][k] = tmp[i][1] / pow(60, abs(k - 2));
      tmp[i][1] %= (int)pow(60, abs(k - 2));
    }
  }
   
  REP(i, 3)
    cout << time[i][0][0] << " " << time[i][0][1] << " " << time[i][0][2] << endl;
   
  return 0;
}
