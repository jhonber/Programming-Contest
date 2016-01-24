#include<bits/stdc++.h>
using namespace std;

int main() {
  int x;
  int cnt = 0;
  for (int i = 0; i < 5; ++i) {
    cin >> x;
    if (x % 2 == 0) cnt ++;
  }

  cout << cnt << " valores pares" << endl;
  return 0;
}