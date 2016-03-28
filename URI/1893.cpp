#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b;
  cin >> a >> b;

  if (a > b && b >= 3 && b <= 96 ) cout << "minguante";
  else if (b >= 0 && b <= 2) cout << "nova";
  else if (b >= 3 && b <= 96) cout << "crescente";
  else cout << "cheia";
  cout << endl;

  return 0;
}
