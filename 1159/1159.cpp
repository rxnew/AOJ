#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, p, c, i;
  while(cin >> n >> p, (c = p) || n) {
    vector<int> h(n, 0);
    for(i = 0; ; i = ++i % n) {
      if(c) h[i]++, c--;
      else c = h[i], h[i] = 0;
      if(!c && h[i] == p) break;
    }
    cout << i << endl;
  }
  return 0;
}
