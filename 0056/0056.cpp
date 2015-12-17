#include <iostream>
#include <math.h>
using namespace std;

bool prime[50001];

int main() {
  int n;

  while(cin >> n, n) {
    int ans = 0;

    prime[0] = false, prime[1] = false;
    for(int i = 2; i <= n; i++)
      prime[i] = true;
    for(int i = 2; i <= sqrt(n); i++) {
      if(prime[i]) {
	for(int j = i + i; j <= n; j += i) {
	  prime[j] = false;
	}
      }
    }

    for(int i = 2; i <= n / 2; i++) {
      if(prime[i]) {
	if(prime[n - i])
	  ans++;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
