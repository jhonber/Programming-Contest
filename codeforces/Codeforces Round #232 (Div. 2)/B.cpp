// http://codeforces.com/contest/397/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl;

int main() {
  int T;
  cin >> T;

  int n, l, r;
  while (cin >> n >> l >> r) {
    long long mm = n / l;
    if (mm * r >= n) cout << "Yes";
    else cout << "No";
    cout << endl;
  }

  return 0;
}