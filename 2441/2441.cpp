#include <iostream>
#include <vector>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define MAX 1000000000000000020
using namespace std;

typedef unsigned long long ull;

vector<ull> v = {0, 0};

ull pow10(int n) {
  return stoull(string("1").append(n, '0'));
}

ull row(int n) {
  return n * 8 + 32;
}

void calc(int n) {
  v.push_back(v.back() + row(n) * pow10(n - 2) * 6 - 5);
  if(v.back() < MAX) calc(n + 1);
}

string getFizzBuzz(int k, ull a) {
  string res;
  FOR(i, 1, 16) {
    if(i % 3 == 0) res.append("Fizz");
    if(i % 5 == 0) res.append("Buzz");
    if(i % 3 && i % 5) res.append(to_string(pow10(k - 1) - 10 + a * 15 + i));
  }
  return res;
}

string solve(ull s) {
  int k;
  for(k = 2; s > v[k]; k++);
  s -= v[k - 1];
  ull a = (s + 4) / row(k), b = (s + 4) % row(k) - (a? 0: 5);
  return (getFizzBuzz(k, a) + getFizzBuzz(k, a + 1)).substr(b, 20);
}

int main() {
  calc(2);
  ull s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}
