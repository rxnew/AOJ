#include <bits/stdc++.h>
using namespace std;

int main() {
  double n, p;
  while(cin >> n, n >= 0) {
    if(n >= 256 || modf(n * 16, &p)) {
      cout << "NA" << endl;
      continue;
    }
    cout << bitset<8>(n).to_string() << '.';
    for(int i = 0; i < 4; i++) cout << int(n = modf(n, &p) * 2);
    cout << endl;
  }
  return 0;
}
