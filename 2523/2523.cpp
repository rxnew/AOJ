#include <iostream>
#include <cstdlib>
#include <string.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define NANO 1000000000
using namespace std;

typedef unsigned long long ull;

ull power(int n, int deg, ull sum) {
  ull tmp = 1;

  REP(i, deg)
    if((tmp *= n) > NANO)
      return 0;
  
  return sum + tmp;
}

int main() {
  int n, t;
  ull op_n = 0, ans;
  char f[40];
  char* p;

  cin >> n >> t >> f;
  
  for(int i = 0; (p = strtok((i)? NULL : f, "n^+")) != NULL; i++)
    if((op_n = power(n, atoi(p), op_n)) == 0)
      break;

  if(op_n && (ans = op_n * t) <= NANO)
    cout << ans << endl;
  else
    cout << "TLE" << endl;

  return 0;
}
