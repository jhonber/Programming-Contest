// http://codeforces.com/contest/276/problem/C

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
};


int main() { __
  int n,q;
  cin >> n >> q;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  vector< pair<int,int> > queries;
  Fenwick tree(n + 100);
  int l,r;
  for (int i = 0; i < q; ++i) {
    cin >> l >> r; l --; r--;
    queries.push_back(make_pair(l + 1,r + 1));
    tree.inc(l,r,1);
  }

  sort(all(v));

  vector< pair<int,int> > vv;
  for (int i = 0; i < n; ++i)
    vv.push_back(make_pair(tree.get(i),i));

  sort(all(vv));

  vector<int> reordered(n);
  for (int i = 0; i < n; ++i)
    reordered[vv[i].second] = v[i];

  long long image[n + 10];
  image[0] = 0;
  for (int i = 1; i <= n; ++i) {
    image[i] = image[i - 1] + reordered[i - 1];
  }

  long long ans = 0;
  for (int i = 0; i < q; ++i) {
    int a = queries[i].first;
    int b = queries[i].second;
    ans += image[b] - image[a - 1];
  }

  cout << ans;

  return 0;
}