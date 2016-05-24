#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  vector<int> v(4);
  for (int i = 0; i < 4; ++i) cin >> v[i];

  sort(v.begin(), v.end());

  int found = false;
  do {
    vector<int> v2(3);
    v2[0] = v[0];
    v2[1] = v[1];
    v2[2] = v[2];

    sort(v2.begin(), v2.end());
    if (v2[2] < v2[0] + v2[1]) {
      found = true;
      break;
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << (found ? "S" : "N") << endl;
  return 0;
}