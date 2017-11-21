// http://codeforces.com/contest/892/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  long long tot = 0;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    tot += a;
  }

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    v.push_back(a);
  }


  sort(v.begin(), v.end());

  if (v[n - 1] + v[n - 2] >= tot) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}