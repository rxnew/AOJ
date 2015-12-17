#include <iostream>

using namespace std;

int num;
void Up(int);

int main() {
  int n;
  while(cin >> n && n > 0) {
    num = 0;
    Up(n);
    if(num % 10) num = num / 10 + 1;
    else num /= 10;
    if(num % 365) num = num / 365 + 1;
    else num /= 365;
    cout << num << endl;
  }

  return 0;
}

void Up(int n) {
  if(n == 0) num++;
  if(n >= 1) Up(n - 1);
  if(n >= 2) Up(n - 2);
  if(n >= 3) Up(n - 3);
  return;
}
