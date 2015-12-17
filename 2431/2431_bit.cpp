#include <iostream>
#include <vector>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)

using namespace std;

typedef long long ll;

class BIT {
 private:
  ll n_;
  vector<ll> v_;
  void update(ll k, ll x) {
    while(k <= n_ && x > v_[k]) v_[k] = x, k += (k & -k);
  }
  ll query(ll i) {
    return (i)? max(v_[i], query(i - (i & -i))): 0;
  }
 public:
  BIT(ll n) {
    for(n_ = 1; n_ < n; n_ *= 2);
    v_.assign(n_ + 1, 0);
  }
  ll calc(vector<ll>& x) {
    REP(i, x.size()) update(x[i], x[i] + query(x[i]));
    return v_[n_];
  }
};

int main() {
  ll n;
  cin >> n;
  vector<ll> x(n, 0);
  REP(i, n) cin >> x[i];
  BIT bit(n);
  cout << n * (n + 1) / 2 - bit.calc(x) << endl;
  return 0;
}
