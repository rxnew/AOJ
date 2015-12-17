#include <iostream>
using namespace std;

int main() {
  char s[1000002], *p;
  int i, j, k, level = 0;

  cin >> s;

  p = s;
  while(*p != '\0') {
    if(*p == 'J') {
      for(i = 0; *p == 'J'; i++, p++);
      for(j = 0; *p == 'O' && j < i; j++, p++);
      for(k = 0; *p == 'I' && k < j; k++, p++);
      if(j == k) {
	level = max(level, j);
      }
    }
    else
      p++;
  }

  cout << level << endl;

  return 0;
}
