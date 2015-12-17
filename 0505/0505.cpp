#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main() {
  int n, m, *survey, ans, max;
  ofstream ofs("output.txt");

  while(cin >> n >> m, (n || m)) {
    survey = (int*)malloc(sizeof(int) * m);
    for(int i = 0; i < m; i++)
      survey[i] = 0;
    while(n--) {
      for(int i = 0; i < m; i++) {
	cin >> ans;
	survey[i] += ans;
      }
    }
    
    for(int cnt = 0; cnt < m; cnt++) {
      max = 0;
      for(int i = 1; i < m; i++) {
	if(survey[max] < survey[i])
	  max = i;
      }
      if(cnt) ofs << " ";
      ofs << max + 1;
      survey[max] = -1;
    }
    ofs << endl;

    free(survey);
  }

  return 0;
}
