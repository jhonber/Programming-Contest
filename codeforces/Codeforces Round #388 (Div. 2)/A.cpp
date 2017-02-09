// http://codeforces.com/contest/749/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int f = false;
  int two = 0;
  if (n % 2 == 0) {
    two = n / 2;
  }
  else {
    two = (n / 2) - 1;
    f = true;
  }

  cout << two + f << endl;
  for (int i = 0; i < two; ++i) {
    cout << 2 << " ";
  }

  if (f) cout << 3 << endl;

  return 0;
}