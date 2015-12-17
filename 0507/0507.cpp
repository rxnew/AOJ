#include <iostream>
#include <vector>
using namespace std;

vector<int> sq;
vector<int>::iterator it;

void Square(int n, int use) {
  sq.push_back(use);
  if(n == use) {
    for(it = sq.begin(); it != sq.end() - 1; it++)
      cout << *it << " ";
    cout << *it << endl;
  }
  for(int i = min(n - use, use); i > 0; i--) {
    Square(n - use, i);
  }
  sq.pop_back();
}

int main() {
  int n;
  vector<int>::iterator it;

  while(cin >> n, n) {
    for(int i = n; i > 0; i--)
      Square(n, i);
  }
  
  return 0;
}
