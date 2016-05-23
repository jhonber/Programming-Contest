#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int tc = 1;
  int t;
  while (cin >> t) {
    vector<int> v;
    int size = t;
    while (t --> 0) {
      int a;
      cin >> a;
      v.push_back(a);
    }

    sort(v.begin(), v.end());
    cout << "Case " << tc ++ << ": " << v[size/2] << endl;
  }

  return 0;
}