// http://codeforces.com/contest/527/problem/B

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

int hammimg (string &a, string &b) {
  int d = 0;
  for (int i = 0; i < a.size(); ++i) if (a[i] != b[i]) d ++;
  return d;
}

int main(){
  int n;
  cin >> n;

  string a, b;
  cin >> a >> b;

  int h1 = hammimg(a, b);
  int h2 = h1;

  map< pair<char, char>, int> mapa;
  map<char, int> mp;
  for (int i = 0; i < n; ++i) if (a[i] != b[i]) {
    mapa[make_pair(b[i], a[i])] = i + 1;
    mp[a[i]] = i + 1;
  }

  int ii, jj;
  pair<char, char> cur;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      cur = make_pair(a[i], b[i]);
      if (mapa[cur]) {
        ii = i + 1;
        jj = mapa[cur];
        h2 = h1 - 2;
        break;
      }
    }
  }

  if (h1 == h2) {
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i] and mp[b[i]]) {
        ii = i + 1;
        jj = mp[b[i]];
        h2 = h1 - 1;
        break;
      }
    }
  }

  if (h1 == h2) cout << h1 << endl << "-1 -1";
  else cout << h2 << endl << ii << " " << jj;
  return 0;
}