#include <iostream>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int main() {
  int q, c, a, n, ans[101] = {0};

  cin >> q;
  REP(i, q) {
    cin >> c >> a >> n;

    /* ナビゲーターの数だけチームを作る */
    while(c && a && n)
      c--, a--, n--, ans[i]++;
    /* 残ったアルゴリズマーの数だけチームを作る */
    while(c >= 2 && a)
      c -= 2, a--, ans[i]++;
    /* 残ったコーダーの数だけチームを作る */
    while(c >= 3)
      c -= 3, ans[i]++;
  }
    
  REP(i, q)
    cout << ans[i] << endl;

  return 0;
}
