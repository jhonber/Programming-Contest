#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

string f (string a) {
  int t = atoi(a.c_str());

  if (t < 10) return "0" + a;
  return a;
}

int main() {
  int n;
  cin >> n;

  while (n --> 0) {
    string a, b, c;
    cin >> a >> b >> c;

    cout << f(a) << ":" << f(b) << " - " << (c == "1" ? "A porta abriu!" : "A porta fechou!");
    cout << endl;
  }

  return 0;
}