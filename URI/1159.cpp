#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  while (cin >> n) {
    if (!n) break;
    int sum = 0;
    for (int i = 0; i < 5; ) {
      if (n % 2 == 0) {
        sum += n;
        i ++;
      }
      n ++;
    }
 
    cout << sum << endl;
  }
 
  return 0;
}
