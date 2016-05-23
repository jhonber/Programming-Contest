#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << (x) << endl;

int main() {
  int j = 7;
  for (int i = 1; i <= 9; i += 2) {
    int t = j;
    for (int k = 0; k < 3; ++k) {
      cout << "I=" << i << " J=" << j << endl;
      j --;
    }
    j = t + 2;
  }

  return 0;
}