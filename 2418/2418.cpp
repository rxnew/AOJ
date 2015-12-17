#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, t, h, l, man = 0, sum = 0;
  bool flg = true, fst = true;

  cin >> n >> t >> h >> l;

  int ti[n], hi[n];

  REP(i, n)
    cin >> ti[i] >> hi[i];
  
  for(int stt = t; stt >= 0 && flg; sum = 0) {
    for( ; sum < 90 && flg; fst = false) {
      if(!fst)
	man = ++man % n;
      if(ti[man])
	ti[man]--, stt++, sum += 10;
      else if(hi[man])
	hi[man]--, sum += 100;
      else
	flg = false;
      if(stt > l)
	flg = false;
    }
    
    stt -= (sum - 90) / 10, ti[man] += (sum - 90) / 10;
  }

  cout << man + 1 << endl;

  return 0;
}
