#include <iostream>
using namespace std;

bool check(char p, char q) {
  if(p == 'A' && q == 'B')
    return true;
  if(p == 'B' && q == 'C')
    return true;
  if(p == 'C' && q == 'F')
    return true;
  if(p == 'F' && q == 'I')
    return true;
  if(p == 'I' && q == 'H')
    return true;
  if(p == 'H' && q == 'G')
    return true;
  if(p == 'G' && q == 'D')
    return true;
  if(p == 'D' && q == 'A')
    return true;
  if(p == 'E')
    if(q == 'B' || q == 'F' || q == 'H' || q == 'D')
      return true;

  return false;
}

int main() {
  char s[11], *p;

  for(int i = 0; i < 1000; i++) {
    bool res = true;

    cin >> s;
    for(p = s; *(p + 1) != '\0'; p++) {
      if(!(check(*p, *(p + 1)) || check(*(p + 1), *p))) {
	res = false;
	break;
      }
    }
    if(res)
      cout << s << endl;
  }

  return 0;
}
