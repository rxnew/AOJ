#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {
  short int rhom[100][100];
  char buf[256], *p;
  int row, col, num;

  for(row = 0; row < 100; row++) {
    cin >> buf;
    if((p = strtok(buf, ",")) != NULL) rhom[row][0] = (short int)atoi(p);
    for(col = 1; col < 100 && (p = strtok(NULL, ",")) != NULL; col++) {
      rhom[row][col] = (short int)atoi(p);
    }
    if(col == 1 && row != 0) break;
  }
  
  num = row;

  for(row = 1; row <= num / 2; row++) {
    for(col = 0; col <= row; col++) {
      if(col == 0)
	rhom[row][col] += rhom[row - 1][col];
      else if(col == row)
	rhom[row][col] += rhom[row - 1][col - 1];
      else {
	if(rhom[row - 1][col - 1] >= rhom[row - 1][col])
	  rhom[row][col] += rhom[row - 1][col - 1];
	else
	  rhom[row][col] += rhom[row - 1][col];
      }
    }
  }

  while(row <= num) {
    for(col = 0; col <= num - row; col++) {
      if(rhom[row - 1][col] >= rhom[row - 1][col + 1])
	rhom[row][col] += rhom[row - 1][col];
      else
	rhom[row][col] += rhom[row - 1][col + 1];
    }
    row++;
  }

  cout << rhom[row - 1][0] << endl;

  return 0;
}
