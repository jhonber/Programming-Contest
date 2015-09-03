// http://codeforces.com/contest/109/problem/A

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

string lucky(int n) {
  int low = ceil(n / 7.);
  int upe = ceil(n / 4.);

  while (low <= upe) {
    int tmp = low * 7;
    int x = low, y = 0;
    while (y <= low) {
      int r = y * 3;
      if (tmp - r == n) {
        string rez;
        for (int i = 0; i < y; ++i) rez += "4";
        for (int i = 0; i < x; ++i) rez += "7";
        return rez;
      }
      x --;
      y ++;
    }

    low ++;
  }
  return "-1";
}

int main() {
  int n; cin >> n;

  string ans = lucky(n);
  cout << ans;

  return 0;
}