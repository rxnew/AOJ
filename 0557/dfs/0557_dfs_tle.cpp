#include <iostream>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int z[101], n;

int dfs(int i, int sum, int op) {
  if(i >= n - 1) {
    if(sum == z[n - 1])
      return 1;
    else
      return 0;
  }
  sum += z[i] * op;
  if(sum < 0 || sum > 20)
    return 0;

  return dfs(i + 1, sum, 1) + dfs(i + 1, sum, -1);
}

int main() {
  cin >> n;
  REP(i, n)
    cin >> z[i];

  cout << dfs(0, 0, 1) / 2 << endl;

  return 0;
}
