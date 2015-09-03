// http://codeforces.com/contest/16/problem/A

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

int main() {
  int n,m;
  cin >> n >> m;

  string bef;
  cin >> bef;
  set<char> st1;
  char t1,t2;
  for (int i = 0; i < m; ++i) st1.insert(bef[i]);
  t1 = bef[0];

  if (n == 1) {
    if (st1.size() == 1) cout << "YES";
    else cout << "NO";
    return 0;
  }

  string cur;
  for (int i = 1; i < n; ++i) {
    cin >> cur;
    t2 = cur[0];
    set<char> st2;
    for (int j = 0; j < m; ++j) st2.insert(cur[j]);

    if (st1.size() != 1 || st2.size() != 1 || t1 == t2) {
      cout << "NO";
      return 0;
    }
    st1 = st2;
    t1 = t2;
  }

  cout << "YES";

  return 0;
}