#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double x;
  while (cin >> x) {

    stringstream ss;
    ss << x;
    string num;
    ss >> num;

    if (num[0] != '-') cout << "+";
    cout << setprecision(4) << scientific << uppercase << x << endl;
  }
  return 0;
}
