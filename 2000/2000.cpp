#include <iostream>
#include <map>
using namespace std;

int main() {
  bool result, field[21][21];
  int n_jew, n_ord, n_disc, jew[2], robo[2];
  pair<char, int> ord[30];
  typedef pair<int, int> coord;
  map<char, coord> dir;
  dir['N'].first = 0, dir['N'].second = 1;
  dir['E'].first = 1, dir['E'].second = 0;
  dir['S'].first = 0, dir['S'].second = -1;
  dir['W'].first = -1, dir['W'].second = 0;

  while(cin >> n_jew, n_jew != 0) {
    result = false;
    for(int i = 0; i < 21; i++) {
      for(int j = 0; j < 21; j++)
	field[i][j] = false;
    }
    n_disc = 0;
    robo[0] = 10, robo[1] = 10;

    for(int i = 0; i < n_jew && i < 20; i++) {
      cin >> jew[0] >> jew[1];
      field[jew[0]][jew[1]] = true;
    }
    cin >> n_ord;
    for(int i = 0; i < n_ord && i < 30; i++)
      cin >> ord[i].first >> ord[i].second;
  
    for(int i = 0; !result && i < n_ord && i < 30; i++) {
      for(int cnt = 0; cnt < ord[i].second; cnt++) {
	robo[0] += dir[ord[i].first].first;
	robo[1] += dir[ord[i].first].second;
	if(field[robo[0]][robo[1]]) {
	  field[robo[0]][robo[1]] = false;
	  if(++n_disc == n_jew) {
	    result = true;
	    break;
	  }
	}
      }
    }
    
    if(result)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}
