#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

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

int main() {
  int n;

  while (cin >> n) {
    if (!n) break;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    Fenwick tree(n + 10);
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      long long val = tree.get(v[i] - 1);
      ans += val;
      tree.add(v[i], 1);
    }


    cout << ((ans % 2) == 0 ? "Carlos" : "Marcelo")<< endl;
  }

  return 0;
}