// http://codeforces.com/contest/813/problem/B

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

vector<long long> all;

void gen (long long x, long long y, long long l, long long r) {
  vector<long long> aa, bb;
  long long a = 1;
  aa.push_back(1);

  while (a <= 1e18 / x) {
    a *= x;
    aa.push_back(a);
  }

  long long b = 1;
  bb.push_back(1);
  while (b <= 1e18 / y) {
    b *= y;
    bb.push_back(b);
  }

  set<long long> st;
  st.insert(l - 1);
  st.insert(r + 1);
  for (auto i: aa) {
    for (auto j: bb) {
      if (i + j >= l && i + j <= r) {
        st.insert(i + j);
      }
    }
  }

  copy(st.begin(), st.end(), back_inserter(all));
}

int main() {
  long long x, y, l, r;
  while (cin >> x >> y >> l >> r) {
    all.clear();
    gen (x, y, l, r);

    long long ans = 0;
    for (int i = 1; i < all.size(); ++i) {
      ans = max(ans, all[i] - all[i - 1] - 1);
    }

    cout << ans << endl;
  }

  return 0;
}