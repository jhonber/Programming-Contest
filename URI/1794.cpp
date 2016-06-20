#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  int good = false;
  if (n >= a && n <= b && n >= c && n <= d) good = true;

  cout << (good ? "possivel" : "impossivel") << endl;
  return 0;
}