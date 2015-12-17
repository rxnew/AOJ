#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, m, p, tmp, winx;

  while(cin >> n >> m >> p, n || m || p) {
    int x = 0;
    
    REP(i, n) {
      cin >> tmp;
      x += tmp;
      if(i == m - 1)
	winx = tmp;
    }
    
    cout << ((winx)? (int)(x * (100 - p) / winx) : 0) << endl;
  }

  return 0;
}
