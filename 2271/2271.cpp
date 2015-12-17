#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> v;
  string t = "KUPC", s;
  cin >> s;
  auto f = [&](char c){int n = 0; for(auto a: s) if(a == c) n++; return n;};
  for(auto a: t) v.push_back(f(a));
  cout << *min_element(v.begin(), v.end()) << endl;
  return 0;
}
