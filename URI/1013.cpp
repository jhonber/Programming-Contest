#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];

  sort(v.begin(), v.end());
  cout << v[2] << " eh o maior" << endl;;
  return 0;
}