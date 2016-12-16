#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int v[3];
  cin >> v[0] >> v[1] >> v[2];

  sort(v, v + 3);

  int ok = false;
  if (v[0] == v[1] || v[1] == v[2] ||
      v[0] + v[1] == v[2] || v[1] + v[2] == v[0] ||
      v[0] + v[2] == v[1]) {

    ok = true;
  }

  cout << (ok ? 'S' : 'N') << endl;

  return 0;
}