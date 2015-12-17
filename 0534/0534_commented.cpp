#include <iostream>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int main() {
  int c[10001];
  int n;
  int tmp;

  while(cin >> n, n) {
    REP(i, n)
      cin >> c[i];
    
    int m = n;
    
    REP(i, n) {
      FOR(start_color, 1, 4) {
	int top = 0, btm = 0, rm_top, rm_btm;
	int start = 1;
	
	if(!(start_color ^ c[i]))
	  continue;
	
	for(int cur_color = start_color; top + btm < n; cur_color = c[i - (top + 1)]) {      
	  for(rm_top = 0; ; rm_top++)
	    if((tmp = i - (top + rm_top + 1)) < 0 || c[tmp] != cur_color)
	      break;
	  
	  for(rm_btm = 0; ; rm_btm++)
	    if((tmp = i + (btm + rm_btm + 1)) >= n || c[tmp] != cur_color)
	      break;
	  
	  if(rm_top + rm_btm + start >= 4)
	    top += rm_top, btm += rm_btm;
	  else
	    break;
	  
	  start = 0;
	}
	
	if(top + btm > 0)
	  m = min(m, n - (top + btm + 1));
      }
    }
    
    cout << m << endl;
  }

  return 0;
}
