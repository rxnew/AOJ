#include <iostream>
#include <cmath>
#define INF 9999999
using namespace std;

typedef long long ll;

int main() {
  ll e, tmp;
  
  for(ll m = INF; cin >> e, e; m = INF) {
    for(int z = 0; (tmp = z * z * z) <= e; z++) {
      ll y = (ll)sqrt(e - tmp);
      m = (ll)min((e - (ll)pow((double)y, 2) - tmp + y + z), m);
    }

    cout << m << endl;
  }

  return 0;
}
