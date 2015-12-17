#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while(cin >> n) {
    bitset<10> a(n);
    int c = 0;
    for(int i = 0; i < 10; i++)
      if(a[i]) cout << (c++ ? " " : "") << (1 << i);
    cout << endl;
  }
  return 0;
}
