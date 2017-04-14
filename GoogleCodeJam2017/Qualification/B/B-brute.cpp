#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

vector<long long> vv;

void gen (int lim) {
  for (int i = 1; i < lim; ++i) {
    int n = i;
    vector<int> v;
    while (n > 0) {
      v.insert(v.begin(), n % 10);
      n /= 10;
    }

    bool ok = true;
    for (int i = 1; i < v.size(); ++i) {
      if (v[i - 1] > v[i]) {
        ok = false;
        break;
      }
    }

    if (ok) {
      vv.push_back(i);
    }
  }
}

int main() {
  gen(2e6);

  int t, TC = 1;
  cin >> t;

  while (t --> 0) {
    long long n;
    cin >> n;

    int ind = lower_bound(vv.begin(), vv.end(), n) - vv.begin();
    if (vv[ind] > n) {
      ind --;
    }

    cout << "Case #" << TC ++ << ": " << vv[ind] << endl;
  }


  return 0;
}
