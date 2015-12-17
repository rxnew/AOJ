#include <iostream>

using namespace std;

int num;
void Collatz(int);

int main() {
  int n;
  while(cin >> n && n > 0) {
    num = 0;
    Collatz(n);
    cout << num << endl;
  }

  return 0;
}

void Collatz(int n) {
  if(n == 1) return;
  num++;
  if(n % 2) Collatz(n * 3 + 1);
  else Collatz(n / 2);
}
