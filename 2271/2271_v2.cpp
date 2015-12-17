#include <bits/stdc++.h>
#define ALL(v) (v).begin(), (v).end()
using namespace std;

int main() {
  int n = INT_MAX;
  string t = "KUPC", s;
  cin >> s;
  for(auto a: t) n = min(n, (int)count(ALL(s), a));
  cout << n << endl;
  return 0;
}
