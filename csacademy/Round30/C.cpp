// https://csacademy.com/contest/virtual6147/task/constant-sum/

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

class Fenwick {
  vector <long double> v;
  int maxSize;

  public:
  Fenwick(int _maxSize) : maxSize(_maxSize+1){
    v = vector <long double>(maxSize, 0LL);
  }

  void add(int where, long double what){
    for (where++; where <= maxSize; where += where & -where){
      v[where] += what;
    }
  }

  long double query(int where){
    long double sum = v[0];
    for (where++; where > 0; where -= where & -where){
      sum += v[where];
    }
    return sum;
  }

  void inc( int a, int b, long double what ) {
    add( a, what );
    add( b+1, -what );
  }

  long double get( int index ) {
    return query(index);
  }

  void print() {
    for (int i = 0; i < v.size(); ++i) cout << v[i] << " "; cout << endl;
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  Fenwick tree(n + 10);

  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    tree.inc(i + 1,i + 1, t);
  }

  cout << fixed << setprecision(16);

  while (q --> 0) {
    int t;
    cin >> t;

    if (t) {
      int i;
      cin >> i;
      cout << tree.get(i) << endl;
    }
    else {
      int i;
      long double s;
      cin >> i >> s;

      long double si = s / (n - 1.0);
      tree.inc(0, n, -si);
      tree.inc(i, i, s + si);
    }
  }

  return 0;
}
