#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, d;
  while (cin >> a >> d) {
    if (!a) break;

    vector<int> v1(a), v2(d);
    for (int i = 0; i < a; ++i) cin >> v1[i];
    for (int i = 0; i < d; ++i) cin >> v2[i];

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int offside = false;
    if (v1[0] < v2[0] || v1[0] >= v2[0] && v1[0] < v2[1]) offside = true;
    cout << (offside ? "Y" : "N") << endl;
  }

  return 0;
}