#include <iostream>
#include <vector>
#define FOR(i, a, n) for(int i = (int)a; i < (int)n; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

bool isMatch(string& B, string& N) {
  for(int i = (int)N.size() - 1; i >= 0; i--)
    if(N[i] != '*' && N[i] != B[i]) return false;
  return true;
}

int solve(vector<string>& N, vector<int>& M, vector<string>& B) {
  int result = 0;
  REP(i, B.size()) {
    REP(j, N.size()) {
      if(isMatch(B[i], N[j])) {
        result += M[j];
        break;
      }
    }
  }
  return result;
}

int main() {
  int n, m;
  while(cin >> n >> m, n) {
    vector<string> N(n), B(m);
    vector<int> M(n);
    REP(i, n) cin >> N[i] >> M[i];
    REP(i, m) cin >> B[i];
    cout << solve(N, M, B) << endl;
  }
  return 0;
}
