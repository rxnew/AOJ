#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, m, op;
  queue<int> cards;
  queue<int> tmp;

  cin >> n >> m;
  for(int i = 1; i <= 2 * n; i++)
    cards.push(i);
  while(m--) {
    cin >> op;
    if(op) {
      while(op--) {
	cards.push(cards.front());
	cards.pop();
      }
    }
    else {
      for(int i = 0; i < n; i++) {
	tmp.push(cards.front());
	cards.pop();
      }
      for(int i = 0; i < n; i++) {
	cards.push(tmp.front());
	cards.push(cards.front());
	tmp.pop();
	cards.pop();
      }
    }
  }
  while(!cards.empty()) {
    cout << cards.front() << endl;
    cards.pop();
  }

  return 0;
}
