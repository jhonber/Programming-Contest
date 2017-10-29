// http://codeforces.com/contest/296/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

class Fenwick {
  vector <long long> v;
  int maxSize;

  public:
  Fenwick(int _maxSize) : maxSize(_maxSize+1){
    v = vector <long long>(maxSize, 0LL);
  }

  void add(int where, long long what){
    for (where++; where <= maxSize; where += where & -where){
      v[where] += what;
    }
  }

  long long query(int where){
    long long sum = v[0];
    for (where++; where > 0; where -= where & -where){
      sum += v[where];
    }
    return sum;
  }

  void inc( int a, int b, long long what ) {
    add( a, what );
    add( b+1, -what );
  }

  long long get( int index ) {
    return query(index);
  }

  void print() {
    for (int i = 0; i < v.size(); ++i) cout << v[i] << " "; cout << endl;
  }
};

int main() { IO;
  int n, m ,k;
  while (cin >> n >> m >> k) {
    vector<int> l(m), r(m), d(m);
    Fenwick ans(n + 100);

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ans.inc(i, i, x);
    }
    for (int i = 0; i < m; ++i) {
      cin >> l[i] >> r[i] >> d[i];
    }

    Fenwick frec(m + 100);

    for (int i = 0; i < k; ++i) {
      int x, y;
      cin >> x >> y; x --; y --;
      frec.inc(x, y, 1);
    }

    for (int i = 0; i < m; ++i) {
      long long tot = frec.get(i) * (d[i] + 0LL);
      ans.inc(l[i] - 1, r[i] - 1, tot);
    }

    for (int i = 0; i < n; ++i) cout << ans.get(i) << " "; cout << endl;
  }

  return 0;
}