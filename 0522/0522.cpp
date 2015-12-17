#include <iostream>
#include <string>
using namespace std;

int checkMatch(string::iterator it) {
  if(*(++it) == 'O')
    if(*(++it) == 'I')
      return 1;
  return 0;
}

int main() {
  string str;
  string::iterator it;

  while(getline(cin, str)) {
    int cntJOI = 0, cntIOI = 0;

    for(it = str.begin(); it + 2 != str.end(); it++) {
      if(*it == 'J')
	cntJOI += checkMatch(it);
      if(*it == 'I')
	cntIOI += checkMatch(it);
    }

    cout << cntJOI << endl << cntIOI << endl;
  }

  return 0;
}
