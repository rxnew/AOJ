#include <iostream>
#include <algorithm>
using namespace std;

typedef struct island_t {
  int a, b;
} island;

int main() {
  island tmp;
  int n, a, b;

  while(cin >> n, n) {
    island island[n];
    int cost = 0;
    bool ans = true;
    
    for(int i = 0; i < n; i++) {
      cin >> island[i].a >> island[i].b;
    }

    for(int i = 0; i < n; i++) {
      for(int j = n - 1; j > i; j--) {
	if(island[j - 1].b > island[j].b) {
	  tmp = island[j];
	  island[j] = island[j - 1];
	  island[j - 1] = tmp;
	}
      }
    }

    for(int i = 0; i < n; i++) {
      if((cost += island[i].a) > island[i].b) {
	ans = false;
	break;
      }
    }
    
    if(ans)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}
