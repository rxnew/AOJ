#include <iostream>
using namespace std;

bool check(int n, int a) {
  for(int i = a; n > 0; i++)
    n -= i;
  return ((n)? false: true);
}

int main() {
  int n, cnt;
  
  while(cin >> n, cnt = 0, n) {
    for(int a = 1; a < (int)(n / 2) + 1; a++)
      if(check(n, a))
	cnt++;
    cout << cnt << endl;
  }

  return 0;
}
