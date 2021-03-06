// http://codeforces.com/contest/892/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i].first;
      v[i].second = i;
    }

    sort(v.begin(), v.end());
    vector<int> out(n);

    for (int i = 0; i < n; ++i) {
      out[v[i].second] = v[(i + 1) % n].first;
    }

    for (auto i: out) cout << i << " "; cout << endl;
  }

  return 0;
}