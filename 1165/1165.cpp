#include <iostream>
#include <vector>
#define MP make_pair
using namespace std;

typedef pair<int, int> P;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int main() {
  int n, ni, di;

  while(cin >> n, n) {
    vector<P> box(n, MP(0, 0));
    int w[2] = {0}, h[2] = {0};

    for(int i = 1; i < n; i++) {
      cin >> ni >> di;
      box[i] = MP(box[ni].first + dx[di], box[ni].second + dy[di]);
      w[0] = min(w[0], box[i].first), h[0] = min(h[0], box[i].second);
      w[1] = max(w[1], box[i].first), h[1] = max(h[1], box[i].second);
    }

    cout << w[1] - w[0] + 1 << " " << h[1] - h[0] + 1 << endl;
  }

  return 0;
}
