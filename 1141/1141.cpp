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
  int d, n;
  long a;

  while(cin >> a >> d >> n, a || d || n) {
    for( ; n; a += d)
      if(isPrime(a))
	n--;

    cout << a - d << endl;
  }

  return 0;
}
