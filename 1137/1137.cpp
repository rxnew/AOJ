#include <iostream>
#include <cmath>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

const char c[] = {'m', 'c', 'x', 'i'};

int stom(string s) {
  int a, m = 0;

  REP(i, s.length()) {
    if(!(s[i] > '0' && s[i] <= '9')) {
      if(i && s[i - 1] > '0' && s[i - 1] <= '9')
	a = (int)(s[i - 1] - '0');
      else
	a = 1;
      REP(j, 4)
	if(s[i] == c[j])
	  m += a * pow(10, 3 - j);
    }
  }
      
  return m;
}

string mtos(int m) {
  int n;
  string s;

  REP(i, 4) {
    if(n = m / pow(10, 3 - i)) {
      if(n > 1)
	s.append(1, (char)(n + '0'));
      s.append(1, c[i]);
    }
    m %= (int)pow(10, 3 - i);
  }

  return s;
}

int main() {
  int n;
  string s1, s2;

  cin >> n;

  while(n--)
    cin >> s1 >> s2, cout << mtos(stom(s1) + stom(s2)) << endl;

  return 0;
}
