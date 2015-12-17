#include <iostream>
using namespace std;
 
int main() {
  bool ans = true;
  int n, i;
  char p;
  long s = 0;
 
  cin >> n;
 
  for(int count = 0; count < n; count++) {
    cin >> p >> i;
    if(!ans)
      continue;
    if(p == '(')
      s += i;
    else {
      s -= i;
      if(s < 0)
        ans = false;
    }
  }
 
  if(ans && s == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
 
  return 0;
}