#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, m, a[101], b[101];
  int cnt, room;
  bool existFlg;

  cin >> n >> m;
  REP(i, m)
    cin >> a[i] >> b[i];

  for(cnt = 0, room = 1; room <= n; cnt++) {
    int max_room = room;
    existFlg = false;

    REP(i, m)
      if(a[i] <= room)
	if(b[i] == (max_room = max(b[i], max_room)))
	  existFlg = true;
    
    if(!existFlg)
      break;

    room = max_room + 1;
  }

  if(existFlg)
    cout << cnt << endl;
  else
    cout << "Impossible" << endl;

  return 0;
}
