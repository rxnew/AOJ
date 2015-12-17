#include <iostream>
using namespace std;

int main() {
  char str[1003], *p;

  cin.getline(str, sizeof(str));
  for(p = str; *p != '\0'; p++) {
    if(*p <= 'C') 
      (*p) += 23;
    else
      (*p) -= 3;
  }

  cout << str << endl;
  return 0;
}
