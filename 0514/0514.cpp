#include <iostream>
#include <vector>
using namespace std;

typedef struct {
  int p[3], r;
  bool solv;
} set;

int main() {
  int a, b, c, n, cnt, und;
  bool ex;
  set buf;
  vector<int> part;
  vector<set> surv; 

  while(cin >> a >> b >> c, (a || b || c)) {
    cin >> n;

    for(int i = 0; i < a + b + c; i++)
      part.push_back(2);

    for(int i = 0; i < n; i++) {
      cin >> buf.p[0] >> buf.p[1] >> buf.p[2] >> buf.r;
      for(int j = 0; j < 3; j++)
	buf.p[j]--;
      surv.push_back(buf);
      if(surv[i].r) {
	for(int j = 0; j < 3; j++)
	  part[surv[i].p[j]] = 1;
	surv[i].solv = true;
      }
      else
	surv[i].solv = false;
    }
    
    do {
      ex = false;
      for(int i = 0; i < n; i++) {
	if(surv[i].solv) continue;
	cnt = 1;
	for(int j = 0; j < 3; j++) {
	  if(part[surv[i].p[j]] == 2)
	    und = surv[i].p[j];
	  cnt *= part[surv[i].p[j]];
	}
	if(cnt == 2) {
	  if(part[surv[i].p[0]] + part[surv[i].p[1]] + part[surv[i].p[2]] == 4) {
	    part[und] = 0;
	    surv[i].solv = true;
	    ex = true;
	  }
	}
      }
    } while(ex);
    
    for(int i = 0; i < a + b + c; i++)
      cout << part[i] << endl;

    part.clear();
    surv.clear();
  }

  return 0;
}
