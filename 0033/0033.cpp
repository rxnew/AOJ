#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ball;
  cin >> n;
  while(n--) {
    int B = 0, C = 0;
    bool ans = true;
    for(int i = 0; i < 10; i++) {
      cin >> ball;
      if(B < ball)      B = ball;
      else if(C < ball) C = ball;
      else              ans = false;
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}
