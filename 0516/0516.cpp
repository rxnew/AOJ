#include <iostream>
#define MAX_A 100000
using namespace std;

int main() {
  int n, k, a[MAX_A + 1], sum, max_sum;

  while(cin >> n >> k, n || k) {
    sum = 0;
    for(int i = 0; i < n; i++)
      cin >> a[i];

    for(int i = 0; i < k; i++)
      sum += a[i];
    max_sum = sum;
    for(int i = 1; i <= n - k; i++)
      max_sum = max(max_sum, (sum = sum - a[i - 1] + a[i + k - 1]));

    cout << max_sum << endl;
  }

  return 0;
}
