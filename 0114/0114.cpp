#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef unsigned long long ull;

ull gcd(ull m, ull n) {
  return ((n)? gcd(n, m % n): m);
}

ull lcm(ull m, ull n) {
  return m / gcd(m, n) * n;
}

int main() {
  ull a[3], m[3];

  while(true) {
    bool flg = false;
    REP(i, 3)
      cin >> a[i] >> m[i], flg |= a[i] | m[i];
    if(!flg)
      break;
    
    ull cyc[3] = {0};

    REP(i, 3)
      for(ull v = 1; !cyc[i] || v != 1; cyc[i]++)
	v = a[i] * v % m[i];

    cout << lcm(cyc[0], lcm(cyc[1], cyc[2])) << endl;
  }
  
  return 0;
}
