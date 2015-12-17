#include <iostream>
#include <cstdlib>
#include <string.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define NANO 1000000000
using namespace std;

typedef unsigned long long ull;

/* 累乗して合計を計算 */
ull power(int n, int deg, ull sum) {
  ull tmp = 1;

  /* 累乗 */
  REP(i, deg)
    if((tmp *= n) > NANO)   /* 10^9を超える場合 */
      return 0;
  
  return sum + tmp;   /* 合計を返す */
}

int main() {
  int n, t;
  ull op_n = 0, ans;
  char f[40];
  char* p;

  cin >> n >> t >> f;
  
  /* 次数の部分だけ順番に切出し */
  for(int i = 0; (p = strtok((i)? NULL : f, "n^+")) != NULL; i++)
    if((op_n = power(n, atoi(p), op_n)) == 0)   /* 切出した次数分累乗 */
      break;

  /* 命令数が10^9個以下、Tを掛けた値が1秒以下の場合か否か */
  if(op_n && (ans = op_n * t) <= NANO)
    cout << ans << endl;
  else
    cout << "TLE" << endl;

  return 0;
}
