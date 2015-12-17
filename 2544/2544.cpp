#include <iostream>
#include <string>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, q, year;
  string name, ans = "kogakubu10gokan";

  cin >> n >> q;

  REP(i, n) {
    cin >> year >> name;
    if(year <= q)
      ans = name;
  }

  cout << ans << endl;

  return 0;
}
