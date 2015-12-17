#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char pass[22], *p;
  bool big = false, little = false, num = false, clear = true;

  cin.getline(pass, 22);
  if(strlen(pass) < 6)
    clear = false;
  else {
    for(p = pass; *p != '\0'; p++) {
      if(*p >= '0' && *p <= '9')
	num = true;
      if(*p >= 'A' && *p <= 'Z')
	big = true;
      if(*p >= 'a' && *p <= 'z')
	little = true;
    }
    if(!(big && little && num))
      clear = false;
  }

  if(clear)
    cout << "VALID" << endl;
  else
    cout << "INVALID" << endl;

  return 0;
}
