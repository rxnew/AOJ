#include <iostream>
using namespace std;

bool isPrime(long a) {
  if(a == 2)
    return true;
  if(a < 2 || !(a % 2))
    return false;

  for(int i = 3; i <= a / i; i += 2)
    if(!(a % i))
      return false;
    
  return true;
}

int main() {
  int n, ans[2];

  while(cin >> n) {
    for(int i = 0; i < 2; i++)
      for(ans[i] = n + 2 * i - 1; ; ans[i] += 2 * i - 1)
	if(isPrime(ans[i]))
	  break;

    cout << ans[0] << " " << ans[1] << endl;
  }

  return 0;
}
