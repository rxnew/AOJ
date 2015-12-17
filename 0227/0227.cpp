#include <iostream>
#include <queue>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, m, tmp;

  while(cin >> n >> m, n || m) {
    priority_queue<int> p;
    int sum = 0;

    REP(i, n) {
      cin >> tmp;
      p.push(tmp);
    }

    REP(i, n) {
      tmp = p.top(), p.pop();
      if((i + 1) % m != 0)
	sum += tmp;
    }

    cout << sum << endl;
  }

  return 0;
}
