// http://codeforces.com/contest/792/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (int i = 1; i <= n; ++i) v[i - 1] = i;

  int ind = 0;
  for (int i = 0; i < k; ++i) {
    int a;
    cin >> a;

    ind = (ind + a) % (int)v.size();
    cout << v[ind] << " ";
    v.erase(v.begin() + ind);
    ind %= v.size();
  }

  cout << endl;

  return 0;
}