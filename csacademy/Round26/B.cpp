// https://csacademy.com/contest/round-26/#task/odd-pair-sums
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;


  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  if (n == 1) {
    cout << !(v[0] % 2) << endl;
    return 0;
  }

  int a = 0, b = 0;
  int last = v[0];
  for (int i = 1; i < n; ++i) {
    if (v[i] % 2 != last % 2) {
      last = v[i];
      a ++;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (v[0] % 2 != v[i] % 2) {
      last = v[i];
      for (int j = i + 1; j < n; ++j) {
        if (v[j] % 2 != last % 2) {
          last = v[j];
          b ++;
        }
      }
      break;
    }
  }

  int aa = n - (a + 1);
  int bb = n - (b + 1);

  cout << min(aa, bb) << endl;

  return 0;
}
