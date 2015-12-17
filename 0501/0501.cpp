#include <iostream>
#include <map>
#include <stdlib.h>
using namespace std;

int main() {
  int n, m;
  char p, q, *str, *c;
  map<char, char> ex;

  while(cin >> n, n) {
    while(n--) {
      cin >> p >> q;
      ex[p] = q;
    }
    cin >> m;
    str = (char*)malloc(sizeof(char) * (m + 1));
    for(c = str; c - str < m; c++) {
      cin >> *c;
      if(ex.count(*c))
	*c = ex[*c];
    }
    *c = '\0';
    cout << str << endl;
    free(str);
    ex.clear();
  }

  return 0;
}
