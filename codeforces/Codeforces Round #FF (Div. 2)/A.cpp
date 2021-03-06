// http://codeforces.com/contest/447/problem/A

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
  int n,p,xi;
  cin >> p >> n;

  vector<int> v(p,0);
  for (int i=0; i<n; ++i) {
    cin >> xi;
    int mod = xi%p;
    if (mod < p) {
      if (v[mod]) {
        cout << i+1;
        return 0;
      }
      v[mod] = true;
    }
    else {
      cout << -1;
      return 0;
    }
  }
  cout << -1;
  return 0;
}