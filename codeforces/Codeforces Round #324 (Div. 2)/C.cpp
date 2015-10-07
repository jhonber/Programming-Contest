// http://codeforces.com/contest/584/problem/C

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

int diff(string a, string b) {
  int d = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) d ++;
  }
  return d;
}

char getDiff(char a, char b) {
  for (int i = 0; i < 26; ++i) {
    char c = i + 'a';
    if (a != c && b != c) return c;
  }
}

int main() {
  int n, t;
  cin >> n >> t;
  string a, b;
  cin >> a >> b;

  string c = a;

  for (int i = 0; i < n; ++i)
    c[i] = getDiff(a[i], b[i]);

  int d = n;
  if (d > t) {

    for (int i = 0; i < n && d > t; ++i) {
      if (a[i] == b[i]) {
        c[i] = a[i];
        d --;
      }
    }

    int tot = 1;
    int f = 0;
    if (d > t) {
      for (int i = 0; i < n && d > t; ++i) {
        if (a[i] != b[i]) {
          if (f % 2 == 0) {
            c[i] = a[i];
            if (tot % 2 == 0) d --;
            tot ++;
          }
          else {
            c[i] = b[i];
            if (tot % 2 == 0) d --;
            tot ++;
          }
          f ++;
        }
      }
    }
  }

  int d1 = diff(a, c);
  int d2 = diff(b, c);
  if (d1 == d2 && d1 == t) {
    cout << c;
  }
  else {
    cout << -1;
  }

  return 0;
}