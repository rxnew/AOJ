#include <iostream>

using namespace std;

int main() {
  float eye[2];
  int a[] = {0, 0}, b[] = {0, 0}, c[] = {0, 0}, d[] = {0, 0};
  while(cin >> eye[0] >> eye[1]) {
    for(int i = 0; i < 2; i++) {
      if(eye[i] >= 1.1) a[i]++;
      else if(eye[i] >= 0.6) b[i]++;
      else if(eye[i] >= 0.2) c[i]++;
      else d[i]++;
    }
  } 
  cout << a[0] << " " << a[1] << endl;
  cout << b[0] << " " << b[1] << endl;
  cout << c[0] << " " << c[1] << endl;
  cout << d[0] << " " << d[1] << endl;

  return 0;
}
