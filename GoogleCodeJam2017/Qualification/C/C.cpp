#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long t, TC = 1;
  cin >> t;

  while (t --> 0) {
    long long n, k;
    cin >> n >> k;

    map<long long, long long> m;
    m[n] ++;

    long long x, y;
    long long cnt = 1;
    while (m.size() > 0) {
      auto cur = m.rbegin();
      long long val = cur->first;
      long long fre = cur->second;
//      cout << val << ": " << fre << endl;
      m.erase(val);

      long long a = val / 2;
      long long b = a;
      if (val % 2 == 0) b --;

      a = max(a, 0LL);
      b = max(b, 0LL);


//      cout << a << " - " << b << endl;
      x = a;
      y = b;

      if (cnt > k) break;
      if (a) {
        m[a] += fre;
        cnt += fre;
      }
      if (b) {
        m[b] += fre;
        cnt += fre;
      }
    }

    if (x < y) swap(x, y);

    cout << "Case #" << TC ++ << ": " << x << " " << y << endl;
  }

  return 0;
}
