#include <iostream>
#include <string>
using namespace std;

int main() {
  string str, ring;
  int n, cnt = 0;

  cin >> str >> n;
  while(n--) {
    cin >> ring;
    ring += ring;
    if(ring.find(str, 0) != string::npos)
      cnt++;
  }

  cout << cnt << endl;

  return 0;
}
