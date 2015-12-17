#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
  int n, cnt;
  char str[100000], tmp[100000], buf[10], *p;

  while(cin >> n, n) {
    cin >> str;

    while(n--) {
      p = str;
      tmp[0] = '\0';
      for(int i = 0; *p != '\0'; i++) {
	for(cnt = 0; *p == *(p + cnt); cnt++);
	sprintf(buf, "%d", cnt);
	strcat(tmp, buf);
	i += strlen(buf);
	tmp[i] = *p;
	tmp[i + 1] = '\0';
	p += cnt;
      }
      strcpy(str, tmp);
    }

    cout << str << endl;
  }

  return 0;
}
