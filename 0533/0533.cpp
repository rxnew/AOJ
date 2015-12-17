#include <iostream>
#include <queue>
using namespace std;

int main() {
  int num, sum[2] = {0};
  priority_queue<int> que[2];

  for(int t = 0; t < 2; t++) {
    for(int i = 0; i < 10; i++) {
      cin >> num;
      que[t].push(num);
    }
  }

  for(int t = 0; t < 2; t++) {
    for(int i = 0; i < 3; i++)
      sum[t] += que[t].top(), que[t].pop();
  }
  
  cout << sum[0] << " " << sum[1] << endl;

  return 0;
}
