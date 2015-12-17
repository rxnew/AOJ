#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, m, a[101], b[101];
  int cnt, room;
  bool existFlg;

  /* 入力 */
  cin >> n >> m;
  REP(i, m)
    cin >> a[i] >> b[i];

  /* 全ての部屋をカバー出来るまでループ */
  for(cnt = 0, room = 1; room <= n; cnt++) {
    int max_room = room;
    existFlg = false;

    /* 守れる教授を探索 */
    REP(i, m)
      if(a[i] <= room)
	if(b[i] == (max_room = max(b[i], max_room)))
	  existFlg = true;
    
    /* 部屋を守れない場合 */
    if(!existFlg)
      break;

    room = max_room + 1;
  }

  /* 出力 */
  if(existFlg)
    cout << cnt << endl;
  else
    cout << "Impossible" << endl;

  return 0;
}
