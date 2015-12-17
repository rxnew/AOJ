#include <iostream>
#include <vector>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)

using namespace std;

typedef long long ll;

class SegTree {
 private:
  ll n_;
  vector<ll> v_;
  void update(ll k, ll x) {
    v_[k += n_ - 1] = x;
    while(k /= 2) v_[k] = max(v_[k * 2], v_[k * 2 + 1]);
  }
  ll query(ll a, ll b, ll k, ll l, ll r) {
    if(b <= l || a >= r) return 0;
    if(a <= l && b >= r) return v_[k];
    ll vl = query(a, b, k * 2, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
    return max(vl, vr);
  }
 public:
  SegTree(ll n) {
    for(n_ = 1; n_ < n; n_ *= 2);
    v_.assign(n_ * 2, 0);
  }
  ll calc(vector<ll>& x) {
    REP(i, x.size()) update(x[i], x[i] + query(1, x[i], 1, 1, n_));
    return v_[1];
  }
};

int main() {
  ll n;
  cin >> n;
  vector<ll> x(n, 0);
  REP(i, n) cin >> x[i];
  SegTree seg(n);
  cout << n * (n + 1) / 2 - seg.calc(x) << endl;
  return 0;
}
