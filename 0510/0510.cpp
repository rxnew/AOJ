#include <iostream>
using namespace std;

int main() {
  int score, sum[2] = {0, 0};
  
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 4; j++) {
      cin >> score;
      sum[i] += score;
    }
  }

  cout << max(sum[0], sum[1]) << endl;
  return 0;
}
