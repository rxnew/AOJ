#include <iostream>
#include <queue>
using namespace std;

int main() {
  int t, n, k, x, pre_x, len, start;
	
  cin >> t;
	
  while(t--) {
    priority_queue<int> que;   /* 降順ソート */

    cin >> n >> k >> x;
    start = pre_x = x;

    /* 入力しながら前の家との距離をキューへ */
    for(int i = 1; i < n; i++) {
      cin >> x;
      que.push(x - pre_x);
      pre_x = x;
    }

    len = x - start;   /* 左端から右端までの総距離 */

    /* (発電機の数 - 1)個分の間を取り出す */
    for(int i = 0; i < k - 1 && que.size(); i++)
      len -= que.top(), que.pop();

    cout << len << endl;
  }
  
  return 0;
}
