// http://codeforces.com/contest/246/problem/C

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

int main() {__
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  map<int, bool> mapa;
  vector< set<int> > st;
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    set<int> t;
    t.insert(v[i]);
    ans.push_back(v[i]);
    st.push_back(t);
    mapa[v[i]] = true;
  }

  int x = 0;
  while (ans.size() < k) {
    int size = ans.size();
    for (int i = x; i < size; ++i) {
      for (int j = 0; j < n; ++j) {
        int tmp = v[j] + ans[i];
        set<int> t = st[i];
        if (!st[i].count(v[j]) and !mapa[tmp]) {
          t.insert(v[j]);
          st.push_back(t);
          ans.push_back(tmp);
          mapa[tmp] = true;
        }
      }
    }
    x += ans.size() - size;
  }

  for (int i = 0; i < k; ++i) {
    cout << st[i].size();
    foreach(x, st[i]) cout << " " << *x;
    cout << endl;
  }

  return 0;
}