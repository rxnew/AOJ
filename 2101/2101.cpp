#include <iostream>
#include <cmath>

using namespace std;

string solve(int n) {
  int s = ((n > 1)? 1: 0), tmp;
  for(int i = 2; i <= sqrt(n); i++)
    if(n % i == 0)
      tmp = n / i, s += i + ((i != tmp)? tmp: 0);
  if(n > s) return "deficient number";
  if(n < s) return "abundant number";
  return "perfect number";
}

int main() {
  int n;
  while(cin >> n, n) cout << solve(n) << endl;
  return 0;
}
