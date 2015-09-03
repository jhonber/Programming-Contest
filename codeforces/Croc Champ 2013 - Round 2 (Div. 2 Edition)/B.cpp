// http://codeforces.com/contest/299/problem/B

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

  for (int i=0; i<n; ) {
    while (s[i] == '.') ++i;

    int cnt = 0;
    while (s[i] == '#') {
      ++i;
      ++ cnt;
    }

    if (cnt >= k) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
  return 0;
}