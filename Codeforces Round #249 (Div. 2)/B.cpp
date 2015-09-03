// http://codeforces.com/contest/435/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  string n;
  int k;
  cin >> n >> k;

  if (!k) {
    cout << n;
    return 0;
  }

  for (int i=0; i<n.size(); ++i) {
    int mmax = -1;
    int ind;
    for (int j=0; j<k; ++j) {
      if ( j+i+1 < n.size() && toInt(n[j+i+1]) > mmax ) {
        mmax = toInt(n[j+i+1]);
        ind = j+i+1;
      }
    }

    if (mmax > toInt(n[i])) {
      for (int j=ind; j>i; --j) {
        swap(n[j], n[j-1]);
        k --;
      }
    }
  }

  cout << n;
  return 0;
}