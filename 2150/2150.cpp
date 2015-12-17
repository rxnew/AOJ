#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define PB push_back

using namespace std;

vector<bool> prime;

void sieve(int n) {
  prime.assign(n + 1, true);
  prime[0] = false, prime[1] = false;
  int s = sqrt(n) + 1;
  REP(i, s) {
    if(!prime[i]) continue;
    for(int j = i * 2; j < n + 1; j += i)
      prime[j] = false;
  }
}

int solve(int n, int p) {
  vector<int> a, v;
  for(int i = n + 1; a.size() < p; i++)
    if(prime[i]) a.PB(i);
  REP(i, a.size()) FOR(j, i, a.size())
    v.PB(a[i] + a[j]);
  sort(v.begin(), v.end());
  return v[p - 1];
}

int main() {
  int n, p;
  sieve(200000);
  while(cin >> n >> p, n != -1 || p != -1)
    cout << solve(n, p) << endl;
  return 0;
}
