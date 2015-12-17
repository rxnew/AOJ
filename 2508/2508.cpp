#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int encode(char c) {
  if(c >= 'A' && c <= 'Z')
    return c - 'A';
  else
    return c - 'a' + encode('Z') + 1;
}
char decode(int i) {
  if(i <= encode('Z'))
    return i + 'A';
  else
    return i + 'a' - encode('a');
}

int main() {
  int n;
  char s[101];

  while(cin >> n, n) {
    int k[n];

    REP(i, n)
      cin >> k[i];
    cin >> s;

    char *p = s;
    for(int i = 0; *p != '\0'; i++, p++) {
      int tmp = (encode(*p) - k[i % n]);
      while(tmp < 0)
	tmp += encode('z') + 1;

      cout << decode(tmp);
    }

    cout << endl;
  }

  return 0;
}
