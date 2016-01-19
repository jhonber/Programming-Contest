#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string a,b,c,d;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> c >> d;
    int x,y;
    cin >> x >> y;

    if ((x + y) % 2 == 0) {
      if (b == "PAR") cout << a << endl;
      else cout << c << endl;
    }
    else {
      if (b == "IMPAR") cout << a << endl;
      else cout << c << endl;
    }
  }
}