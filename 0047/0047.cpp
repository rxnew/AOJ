#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int main(void) {
  bool cup[3] = {true, false, false}, tmp;
  string buf, ans;
  int num[3];
  while(cin >> buf) {
    for(int i = 0; i < 2; i++) {
      if(buf.at(i*2) == 'A') {
	num[i] = 0;	
      } else if(buf.at(i*2) == 'B') {
	num[i] = 1;
      } else {
	num[i] = 2;
      }
    }
    tmp = cup[num[0]];
    cup[num[0]] = cup[num[1]];
    cup[num[1]] = tmp;
  }
  if(cup[0]) {
    ans = "A";
  } else if(cup[1]) {
    ans = "B";
  } else if(cup[2]) {
    ans = "C";
  }
  cout << ans << endl;
  return 0;
}
