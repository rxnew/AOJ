#include <iostream>
#include <vector>
#include <cmath>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define MAX_N 300000
using namespace std;

vector<bool> mspf() {
  vector<bool> v(MAX_N + 1, false);
  for(int i = 7; i < MAX_N; i += 7)
    v[i - 1] = true, v[i + 1] = true;
  FOR(i, 6, sqrt(MAX_N)) if(v[i])
    for(int j = i + i; j < MAX_N; j += i)
      v[j] = false;
  return v;
}

int main() {
  int n;
  vector<bool> v = mspf();
  while(cin >> n, n != 1) {
    cout << n << ":";
    vector<int> res;
    FOR(i, 6, MAX_N)
      if(v[i] && n % i == 0) res.push_back(i);
    REP(i, res.size()) cout << ' ' << res[i];
    cout << endl;
  }
  return 0;
}
