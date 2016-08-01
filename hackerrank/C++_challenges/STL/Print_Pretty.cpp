// https://www.hackerrank.com/challenges/prettyprint

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int T; cin >> T;
  cout << setiosflags(ios::uppercase);
  cout << setw(0xf) << internal;
  while(T--) {
    double A; cin >> A;
    double B; cin >> B;
    double C; cin >> C;

    // Begin my code
    cout << left << showbase << nouppercase << hex << (long long)A << endl;

    cout << right << setw(15) << setfill('_') << fixed << setprecision(2) << showpos << B << endl;

    cout << scientific << uppercase << setprecision(9) << noshowpos << C << endl;
    // End my code
  }

  return 0;
}
