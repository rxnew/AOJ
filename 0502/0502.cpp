#include <iostream>
#include <map>
using namespace std;

typedef enum {
  North, East, South, West, Right, Left, Top, Bottom
} direct;

map<direct, int> stat;

direct Reverse(direct dir) {
  if(dir == North) return South;
  else if(dir == South) return North;
  else if(dir == East) return West;
  else if(dir == West) return East;
}

void Operation(direct op) {
  int tmp;

  if(op != Right && op != Left) {
    tmp = stat[Top];
    if(op == North || op == West) {
      stat[Top] = stat[Reverse(op)];
      stat[Reverse(op)] = 7 - tmp;
    }
    else {
      stat[Top] = 7 - stat[op];
      stat[op] = tmp;
    }
  }
  else{
    tmp = stat[South];
    if(op == Right) {
      stat[South] = stat[East];
      stat[East] = 7 -tmp;
    }
    else {
      stat[South] = 7 - stat[East];
      stat[East] = tmp;
    }
  }
}

int main() {
  int n, sum;
  string op;

  map<string, direct> convert;
  convert["North"] = North;
  convert["East"] = East;
  convert["South"] = South;
  convert["West"] = West;
  convert["Right"] = Right;
  convert["Left"] = Left;

  while(cin >> n, n) {
    stat[Top] = 1;
    stat[South] = 2;
    stat[East] = 3;
    sum = 1;

    while(n--) {
      cin >> op;
      Operation(convert[op]);
      sum += stat[Top];
    }

    cout << sum << endl;
  }
  return 0;
}
