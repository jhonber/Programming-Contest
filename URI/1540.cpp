#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  double x, y;
  int a, b, c, d;
  while (t --> 0) {
    cin >> a >> b >> c >> d;

    long double tot = c - a;
    long double r = d - b;
    long long ans = (r / tot) * 100;

    int x = (ans % 100);
    stringstream ss;
    ss << x;
    string out;
    ss >> out;

    while (out.size() < 2) out += "0";

    cout << (ans / 100) << "," << out << endl;
  }

  return 0;
}