#include <iostream>

using namespace std;

int main() {
  int n, result = 0;
  cin >> n;
  for(int i = n; i > 1; i = (i + 2) / 3) result++;
  cout << result << endl;
  return 0;
}
