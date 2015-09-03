// http://codeforces.com/contest/143/problem/A

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
  int r1,r2,c1,c2,d1,d2;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      for (int k = 1; k < 10; ++k) {
        for (int l = 1; l < 10; ++l) {
          set<int> st;
          st.insert(i);
          st.insert(j);
          st.insert(k);
          st.insert(l);
          if (st.size() != 4) continue;
          if (i + l == d1 && i + k == c1 && i + j == r1 && k + j == d2 && j + l == c2 && k + l == r2) {
            cout << i << " " << j << endl << k << " " <<  l << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << -1;
  return 0;
}