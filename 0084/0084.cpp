#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char str[1027], *p, cnt = 0;
  cin.getline(str, sizeof(str));
  if((p = strtok(str, " .,")) == NULL) return 0;
  if((int)strlen(p) >= 3 && (int)strlen(p) <= 6) {
    cout << p;
    cnt++;
  }
  while((p = strtok(NULL, " .,")) != NULL) {
    if((int)strlen(p) < 3 || (int)strlen(p) > 6) continue;
    if(cnt) cout << " " << p;
    else {
      cout << p;
      cnt++;
    }
  }
  cout << endl;
  
  return 0;
}
