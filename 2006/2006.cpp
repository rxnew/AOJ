#include <iostream>
#include <map>
using namespace std;

/* C++11 */
map<char, string> keys = {
  {'1', ".,!? "},
  {'2', "abc"},
  {'3', "def"},
  {'4', "ghi"},
  {'5', "jkl"},
  {'6', "mno"},
  {'7', "pqrs"},
  {'8', "tuv"},
  {'9', "wxyz"}
};

int main() {
  int n;

  cin >> n;

  while(n--) {
    char in[1025], key;

    cin >> in;

    for(char* p = in; *p != '\0'; p++) {
      if((key = *p) != '0') {
	int keynum, cnt = 0;

	while(*p != '0')
	  cnt++, p++;
	keynum = (cnt - 1) % (int)keys[key].size();

	cout << keys[key][keynum];
      }
    }
    
    cout << endl;
  }

  return 0;
}
