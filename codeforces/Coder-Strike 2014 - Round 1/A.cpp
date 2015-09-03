// http://codeforces.com/contest/412/problem/A

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
  int n,k;
  cin >> n >> k;

  string s;
  cin >> s;

  int t = (n-k);

  if (t < k-1) {
    int i=1;
    while ( i ++ < t+1)
      cout << "RIGHT" << endl;

    i = n-1;
    while (i >= 0 ) {
      cout << "PRINT " << s[i] << endl;
      if (i>0)
        cout << "LEFT" << endl;
      i --;
    }
  }
  else {
    int i = 1;
    while (i ++ < k)
      cout << "LEFT" << endl;

    i = 0;
    while ( i<n) {
      cout << "PRINT " << s[i] << endl;
      if (i<n-1)
        cout << "RIGHT" << endl;

      i ++;
    }
  }

  return 0;
}