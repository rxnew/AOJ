#include <iostream>
#include <unordered_map>

using namespace std;

const char consonant[] = {'w', '\0', 'k', 's', 't', 'n', 'h', 'm', 'y', 'r'};
unordered_map<char, char> vowel;

void init() {
  vowel['T'] = 'a';
  vowel['L'] = 'i';
  vowel['U'] = 'u';
  vowel['R'] = 'e';
  vowel['D'] = 'o';
}

int main() {
  string buf;
  cin >> buf;
  init();
  for(int i = 0; i < (int)buf.size() - 1; i += 2) {
    if(buf[i] == '0' && buf[i + 1] == 'U')
      cout << "nn";
    else if(buf[i] == '1')
      cout << vowel[buf[i + 1]];
    else
      cout << consonant[buf[i] - '0'] << vowel[buf[i + 1]];
  }
  cout << endl;
  return 0;
}
