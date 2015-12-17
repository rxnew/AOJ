#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h>
using namespace std;
   
int main() {
  int n, t;
  long long op_n = 0, ans;
  char f[40];
  char* p;
   
  cin >> n >> t;
  cin >> f;

  /* 次数の部分だけ順番に切出し */
  for(int i = 0; (p = strtok((i)? NULL : f, "n^+")) != NULL; i++)
    op_n += pow((double)n, (double)atoi(p));   /* 切出した次数分累乗 */
   
  /* 1秒以下か否か */
  if((ans = op_n * t) <= 1000000000 && ans > 0)
    cout << ans << endl;
  else
    cout << "TLE" << endl;
   
  return 0;
}
