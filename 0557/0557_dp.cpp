#include <iostream>
#include <string.h>
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

long long int dp[101][21];
int z[101], n;

long long int func(int i, int sum) {
  if(i >= n - 1) {
    if(sum == z[n - 1])
      return 1;
    else
      return 0;
  }
  if(sum < 0 || sum > 20)
    return 0;
  if(dp[i][sum] != -1)
    return dp[i][sum];

  return dp[i][sum] = func(i + 1, sum + z[i]) + func(i + 1, sum - z[i]);
}

int main() {
  cin >> n;
  REP(i, n)
    cin >> z[i];
  memset(dp, -1, sizeof(dp));
  cout << func(1, z[0]) << endl;

  return 0;
}
