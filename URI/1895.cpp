#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, t, l;
  cin >> n >> t >> l;

  int a = 0, b = 0;
  for (int i = 0; i < n - 1; ++i) {
    int cur ;
    cin >> cur;

    int good = 0;
    if (abs(cur - t) <= l) {
      good += abs(cur - t);
      t = cur;
    }

    if (i % 2 == 0) a += good;
    else b += good;
  }

  cout << a << " " << b << endl;

  return 0;
}