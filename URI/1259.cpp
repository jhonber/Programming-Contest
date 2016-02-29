#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v, v2;
  while (n --> 0) {
    int a;
    cin >> a;

    if (a % 2 == 0) v.push_back(a);
    else v2.push_back(a);
  }

  sort(v.begin(), v.end());
  sort(v2.begin(), v2.end());

  for (int i = 0; i < v.size(); ++i) cout << v[i] << endl;
  for (int i = v2.size() - 1; i >= 0; --i) cout << v2[i] << endl;

  return 0;
}
