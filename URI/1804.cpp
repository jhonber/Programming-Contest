#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

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

int main() { IO
  int n;
  cin >> n;

  Fenwick tree(n + 10);
  int bef;
  cin >> bef;

  tree.inc(1, 1, bef);

  int accum = bef;
  for (int i = 1; i < n; ++i) {
    int a;
    cin >> a;

    accum += a;
    tree.inc(i + 1, i + 1, accum);
  }

  char op;
  int a;
  while (cin >> op >> a) {
    if (op == 'a') {
      int tmp = tree.get(a - 1);
      int tmp2 = tree.get(a);

      int t = tmp2 - tmp;
      tree.inc(a + 1, n, -t);
      tree.inc(a, a, -tmp2 + tmp);
    }
    else {
      cout << tree.get(a - 1) << endl;
    }
  }

  return 0;
}