#include <iostream>
#include <vector>
#define REP(i, n) for(int i = 0; i < n; i++)
#define PB push_back
using namespace std;

int main() {
  int n, tmp;

  while(cin >> n, n) {
    vector<int> page;

    REP(i, n) {
      cin >> tmp;
      page.PB(tmp);
    }

    REP(i, n) {
      if(i)
	cout << " ";
      cout << page[i];
      if(i == n - 1)
	break;
      if(page[i + 1] == page[i] + 1) {
	cout << "-";
	while(++i < n - 1 && page[i + 1] == page[i] + 1);
	cout << page[i];
      }
    }

    cout << endl;
  }

  return 0;
}
