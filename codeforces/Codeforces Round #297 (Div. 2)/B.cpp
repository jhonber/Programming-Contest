// http://codeforces.com/contest/525/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

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
  int m;
  string s;
  cin >> s;

  int n = s.size();
  Fenwick tree(n + 10);

  cin >> m;
  for (int i = 0; i < m; ++i) {
    int q;
    cin >> q; q--;
    tree.inc(q,n - q - 1, 1);
  }

  for (int i = 0; i < n / 2; ++i) {
    int r = tree.get(i) % 2;
    if (r) swap(s[i],s[n - i - 1]);
  }

  cout << s;
  return 0;
}