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
    vector<ull> d(n), v(n), t(n);
    ull v_lcm = 0, t_lcm = 0;
    for(int i = 0; i < n; i++) {
      cin >> d[i] >> v[i];
      v_lcm = v_lcm ? lcm(v_lcm, v[i]) : v[i];
    }
    for(int i = 0; i < n; i++) {
      t[i] = v_lcm / v[i] * d[i];
      t_lcm = t_lcm ? lcm(t_lcm, t[i]) : t[i];
    }
    for(const auto& t_i : t) {
      cout << t_lcm / t_i << endl;
    }
  }
  return 0;
}
