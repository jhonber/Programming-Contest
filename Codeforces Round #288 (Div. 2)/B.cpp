// http://codeforces.com/contest/508/problem/B

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

int main() { __
  string s;
  cin >> s;

  int t = s.size();
  int last = toInt(s[t - 1]);
  for (int i = 0; i < t; ++i) {
    int tmp = toInt(s[i]);
    if (tmp % 2 == 0 && tmp < last) {
      swap(s[i],s[t - 1]);
      cout << s;
      return 0;
    }
  }

  for (int i = t - 1; i >= 0; --i) {
    int tmp = toInt(s[i]);
    if (tmp % 2 == 0) {
      swap(s[i],s[t - 1]);
      cout << s;
      return 0;
    }
  }

  cout << -1;
  return 0;
}