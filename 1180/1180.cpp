#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#define REP(i, n) for(int i = 0; i < n; i++)
#define PB push_back
using namespace std;

string itos(int a, int l) {
  char s[7];
  sprintf(s, "%d", a);
  string str = string(s);
  int clen = l - str.size();
  REP(i, clen)
    str.insert(str.begin(), '0');
  return str;
}

int main() {
  int a0, l, ansi, ansj;
  string la, sa, tmp;

  while(cin >> a0 >> l, a0 && l) {
    bool resFlg = false;
    vector<string> a;

    a.PB(itos(a0, l));

    for(int i = 0; !resFlg; i++) {
      la = a[i], sa = a[i];
      sort(sa.begin(), sa.end());
      sort(la.begin(), la.end(), greater<int>());
      a.PB(itos(atoi(la.c_str()) - atoi(sa.c_str()), l));

      if(i)
	for(int j = 0; !resFlg && j < i; j++)
	  if(a[j] == a[i])
	    ansi = i, ansj = j, resFlg = true;
    }

    cout << ansj << " " << atoi(a[ansi].c_str()) << " " << ansi - ansj << endl;
  }

  return 0;
}
