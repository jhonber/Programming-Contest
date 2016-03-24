#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  while (n --> 0) {
    int a;
    cin >> a;

    if (a == 0) cout << "NULL";
    else {
      if (a < 0) {
        if ((a % 2) == 0) cout << "EVEN NEGATIVE";
        else cout << "ODD NEGATIVE";
      }
      else {
        if ((a % 2) == 0) cout << "EVEN POSITIVE";
        else cout << "ODD POSITIVE";
      }
    }
    cout << endl;
  }

  return 0;
}