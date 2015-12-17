#include <iostream>
#include <cstdlib>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  string num_s;

  cin >> n;
  
  while(n--) {
    cin >> num_s;

    sort(num_s.begin(), num_s.end());
    int snum = atoi(num_s.c_str());
    sort(num_s.begin(), num_s.end(), greater<int>()); 
    int lnum = atoi(num_s.c_str());
    
    cout << lnum - snum << endl;
  }

  return 0;
}
