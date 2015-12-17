#include <cstring>
#include <iostream>
using namespace std;
 
const int MAX_N = 100;
int values[MAX_N];
 
int main(){
  int n;
  while(cin >> n, n != 0){
    int target, ans = 0;
    int l = -1, r = n;
    int cnt = 0;
         
    memset(values, 0, sizeof(values));
    for (int i = 0; i < n; i++) {
      cin >> values[i];
    }
    cin >> target;
 
    for(cnt = 1; r - l > 1; cnt++) {
      int mid = (l + r) / 2;
      if(values[mid] == target) {
	ans = cnt;
	break;
      }
      else if(values[mid] > target)
	r = mid;
      else
	l = mid;
    }
         
    if(ans == 0) {
      ans = cnt - 1;
    }
 
    cout << ans << endl;
  }
  return 0;
}
