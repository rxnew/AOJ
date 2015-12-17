#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;

  cin >> s;
  if(s.at(0) == 'o' || s.at(s.length() - 1) == 'o')
    cout << "o" << endl;
  else
    cout << "x" << endl;

  return 0;
}
