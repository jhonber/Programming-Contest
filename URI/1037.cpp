#include<bits/stdc++.h>
using namespace std;

#define D(x) out = #x << " = " < (x) << endl;

int main() {
  vector<string> ans = {"[0,25]", "(25,50]", "(50,75]", "(75,100]"};

  double x;
  cin >> x;

  int f = true;
  string out;
  if (x >= 0 && x <= 25) {
    out = ans[0];
  }
  else if (x > 25 && x <= 50) {
    out = ans[1];
  }
  else if (x > 50 && x <= 75) {
    out = ans[2];
  }
  else if (x > 75 && x <= 100) {
    out = ans[3];
  }
  else {
    f = false;
  }

  if (f) cout << "Intervalo ";
  else cout << "Fora de intervalo";
  cout << out << endl;

  return 0;
}