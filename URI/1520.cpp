#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      int a,b;
      cin >> a >> b;
      for (int j = a; j <= b; ++j) v.push_back(j);
    }

    sort(v.begin(), v.end());

    int x;
    cin >> x;

    int a = -1, b = -1;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == x) {
        a = i;
        while (i < v.size() && v[i] == x) i ++;
        b = i - 1;
        break;
      }
    }

    if (a == -1 && b == -1) cout << x << " not found" <<endl;
    else cout << x << " found from " << a << " to " << b << endl;
  }

  return 0;
}