#include <iostream>
using namespace std;

int main() {
  char s[101], *p;
  int n;

  while(cin.getline(s, sizeof(s))) {
    for(p = s; *p != '\0'; p++) {
      if(*p == '@') {
	n = *(++p) - '0';
	p++;
	while(n--)
	  cout << *p;
      }
      else
	cout << *p;
    }
    
    cout << endl;
  }

  return 0;
}
