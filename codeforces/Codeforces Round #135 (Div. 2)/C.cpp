// http://codeforces.com/contest/219/problem/C

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

int n, k;

char getLetter (char &a, char &b) {
  for (int i = 0; i <= k; ++i) {
    char c = i + 'A';
    if (c != a and c != b) return c;
  }
}

int main() { __
  string s;

  cin >> n >> k >> s;

  if (k == 2) {
    string a, b;
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        a += "A";
        b += "B";
        if ('A' != s[i]) d1 ++;
        if ('B' != s[i]) d2 ++;
      }
      else  {
        a += "B";
        b += "A";
        if ('B' != s[i]) d1 ++;
        if ('A' != s[i]) d2 ++;
      }
    }

    if (d1 < d2) cout << d1 << endl << a;
    else cout << d2 << endl << b;

    return 0;
  }


  int d = 0;
  for (int i = 1 ; i < n; ++i) if (s[i] == s[i - 1]) {
    char c = getLetter(s[i], s[i + 1]);
    s[i] = c;
    d ++;
  }

  cout << d << endl << s;
  return 0;
}