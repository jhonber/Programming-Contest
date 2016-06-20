#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  vector<int> v(5);
  vector<int> vv(5);
  for (int i = 0; i < v.size(); ++i) cin >> v[i];
  for (int i = 0; i < vv.size(); ++i) cin >> vv[i];

  int ans = true;
  for (int i = 0; i < v.size(); ++i) {
    if (!v[i] != vv[i]) ans = false;
  }

  cout << (ans ? "Y" : "N") << endl;
  return 0;
}