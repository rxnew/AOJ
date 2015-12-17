#include <bits/stdc++.h>
#define FOR(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int main() {
  int n;
  vector<bool> p(10000001, true);
  p[0] = p[1] = false;
  FOR(i, 2, sqrt(p.size())) if(p[i]) for(int j = i * 2; j < p.size(); p[j] = false, j += i);
  while(cin >> n, n) for(int i = n; i > 1; i--) if(p[i] && p[i - 2] && p[i - 6] && p[i - 8]) cout << i << endl, i = 0;
  return 0;
}
