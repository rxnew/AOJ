#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int t, n, s, f;

  for(int sum = 0; cin >> t, t; sum = 0) {
    cin >> n;
    REP(i, n) {
      cin >> s >> f;
      sum += f - s;
    }
    
    if(sum >= t)
      cout << "OK" << endl;
    else
      cout << t - sum << endl;
  }

  return 0;
}
