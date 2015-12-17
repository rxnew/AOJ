#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

typedef long long ll;

ll fact(ll n) {
  if(!n) return 1;
  return n *= fact(n - 1);
}
  
int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  auto it = s.begin();
  vector<ll> cnt;
  int flg = 0;
  ll res = 0;
  while(it != s.end()) {
    int n = 1;
    char c = *it;
    while(++it != s.end() && *it == c) n++;
    res += n / 2;
    cnt.push_back(n / 2);
    if(n % 2 && flg++) {
      cout << 0 << endl;
      return 0;
    }
  }
  res = fact(res);
  REP(i, cnt.size()) if(cnt[i]) res /= fact(cnt[i]);
  cout << res << endl;
  return 0;
}
