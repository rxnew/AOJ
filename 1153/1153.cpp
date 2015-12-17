#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, m;

  while(cin >> n >> m, n || m) {
    int taro[n], hana[m], sum[2] = {0}, ans[2] = {-1};

    REP(i, n)
      cin >> taro[i], sum[0] += taro[i];
    REP(i, m)
      cin >> hana[i], sum[1] += hana[i];

    int diff = sum[0] - sum[1];

    REP(i, n) REP(j, m)
      if((taro[i] - hana[j]) * 2 == diff)
	if(ans[0] == -1 || taro[i] + hana[j] < ans[0] + ans[1])
	  ans[0] = taro[i], ans[1] = hana[j];

    if(ans[0] != -1)
      cout << ans[0] << " " << ans[1] << endl;
    else
      cout << -1 << endl;
  }

  return 0;
}
