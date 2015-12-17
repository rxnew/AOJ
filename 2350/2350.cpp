#include <iostream>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define PB push_back

using namespace std;

int main() {
  string a_s, b_s;
  int k;
  cin >> a_s >> b_s >> k;
  vector<int> a, b, borrow(1, 0), result;
  REP(i, a_s.size()) a.PB(a_s[a_s.size() - i - 1] - '0');
  REP(i, b_s.size()) b.PB(b_s[b_s.size() - i - 1] - '0');
  while(a.size() > b.size()) b.PB(0);
  REP(i, a.size()) borrow.PB(((a[i] - borrow[i] < b[i])? 1: 0));
  for(int i = a.size() - 1; i >= 0; i--) {
    int tmp = a[i] + ((borrow[i + 1])? 10: 0) - b[i];
    if(k && borrow[i] && tmp < 10) result.PB(tmp), k--;
    else result.PB(tmp - borrow[i]);
  }
  while(result.front() == 0) result.erase(result.begin());
  REP(i, result.size()) cout << result[i];
  cout << endl;
  return 0;
}
