#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  vector<int> v(3), vv;
  cin >> v[0] >> v[1] >> v[2];

  vv = v;
  sort(v.begin(), v.end());
  cout << v[0] << endl;
  cout << v[1] << endl;
  cout << v[2] << endl;
  cout << endl;
  cout << vv[0] << endl;
  cout << vv[1] << endl;
  cout << vv[2] << endl;
  return 0;
}
