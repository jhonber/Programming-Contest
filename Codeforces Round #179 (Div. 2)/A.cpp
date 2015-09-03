// http://codeforces.com/contest/296/problem/A

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
  int n;
  cin >> n;

  set<int> st;
  map<int,int> mapa;

  int a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    st.insert(a);
    mapa[a] ++;
  }

  int ant = 0;
  while (st.size()) {
    int mmax = 0;
    int val = 0;
    foreach(x,st) {
      if(mapa[*x] && *x != ant && mmax < mapa[*x]) {
        mmax = mapa[*x];
        val = *x;
      }
    }
    if (val) {
      mapa[val] --;
      ant = val;
      if (!mapa[val]) st.erase(val);
    }
    else {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
  return 0;
}