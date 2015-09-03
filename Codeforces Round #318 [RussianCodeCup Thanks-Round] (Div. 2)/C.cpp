// http://codeforces.com/contest/574/problem/C

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
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  for (int i = 0; i < n; ++i) {
    while (v[i] % 2 == 0) v[i] /= 2;
    while (v[i] % 3 == 0) v[i] /= 3;
  }

  set<int> st;
  for (int i = 0; i < n; ++i) st.insert(v[i]);

  int ans = st.size();
  cout << (ans == 1 ? "Yes" : "No");

  return 0;
}