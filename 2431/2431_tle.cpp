#include <iostream>
#include <vector>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)

using namespace std;

typedef long long ll;

ll getLIS(vector<ll>& x) {
  ll result = 0;
  vector<ll> dp = x;
  REP(i, x.size()) REP(j, i)
    if(x[i] > x[j])
      result = max(result, dp[i] = max(dp[i], dp[j] + x[i]));
  return result;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> x(n, 0);
  REP(i, n) cin >> x[i];
  cout << n * (n + 1) / 2 - getLIS(x) << endl;
  return 0;
}
