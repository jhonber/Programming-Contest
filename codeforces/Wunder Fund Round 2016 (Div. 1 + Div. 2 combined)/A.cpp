// http://codeforces.com/contest/618/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v;
  v.push_back(1);

  for (int i = 1; i < n; ++i) {
    v.push_back(1);

    int j = v.size() - 1;
    while (v.size() > 1 && v[j] == v[j - 1]) {
      int val = v[j];
      v.pop_back();
      v.pop_back();
      v.push_back(val + 1);
      j --;
    }
  }

  for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";

  return 0;
}