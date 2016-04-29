#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

inline auto gcd(ull m, ull n) -> ull {
  return n ? gcd(n, m % n) : m;
}

inline auto lcm(ull m, ull n) -> ull {
  return m / gcd(m, n) * n;
}

auto main() -> int {
  int n;
  while(cin >> n, n) {
    vector<ull> d(n), v(n), p(n);
    ull d_lcm = 0, p_gcd = 0;
    for(int i = 0; i < n; i++) {
      cin >> d[i] >> v[i];
      d_lcm = d_lcm ? lcm(d_lcm, d[i]) : d[i];
    }
    for(int i = 0; i < n; i++) {
      p[i] = d_lcm / d[i] * v[i];
      p_gcd = p_gcd ? gcd(p_gcd, p[i]) : p[i];
    }
    for(const auto& p_i : p) {
      cout << p_i / p_gcd << endl;
    }
  }
  return 0;
}
