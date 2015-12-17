#include <iostream>
using namespace std;

int main() {
  char str[1001];

  cin.getline(str, sizeof(str));

  for(char* p = str; *p != '\0'; p++) {
    if(*p == 'a' && *(p + 1) == 'p' && *(p + 2) == 'p' && *(p + 3) == 'l' && *(p + 4) == 'e') {
      cout << "peach";
      p += 4;
    }
    else if(*p == 'p' && *(p + 1) == 'e' && *(p + 2) == 'a' && *(p + 3) == 'c' && *(p + 4) == 'h') {
      cout << "apple";
      p += 4;
    }
    else
      cout << *p;
  }

  cout << endl;

  return 0;
}
