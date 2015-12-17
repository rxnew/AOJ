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
   
  for(int i = 0; (p = strtok((i)? NULL : f, "n^+")) != NULL; i++)
    op_n += pow((double)n, (double)atoi(p));
   
  if((ans = op_n * t) <= 1000000000 && ans > 0)
    cout << ans << endl;
  else
    cout << "TLE" << endl;
   
  return 0;
}
