#include <iostream>
#include <string.h>
using namespace std;

int main() {
  int a[10], n;

  while(cin >> n) {
    int hit = 0, brow = 0;
    memset(a, -1, sizeof(a));

    a[n] = 0;
    for(int i = 1; i < 4; i++) {
      cin >> n;
      a[n] = i;
    }
    for(int i = 0; i < 4; i++) {
      cin >> n;
      if(a[n] == i)
	hit++;
      else if(a[n] != -1)
	brow++;
    }

    cout << hit << " " << brow << endl;
  }
  
  return 0;
}
