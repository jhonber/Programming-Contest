// http://codeforces.com/contest/106/problem/A

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

int main () {
  map<char, int> mapa;

  mapa['A'] = 20;
  mapa['K'] = 19;
  mapa['Q'] = 18;
  mapa['J'] = 17;
  mapa['T'] = 16;
  mapa['9'] = 15;
  mapa['8'] = 14;
  mapa['7'] = 13;
  mapa['6'] = 12;

  char t;
  cin >> t;
  string a, b;
  cin >> a >> b;


  if (t == a[1] && t == b[1]) cout << (mapa[a[0]] > mapa[b[0]] ? "YES" : "NO");
  else if (t == a[1]) cout << "YES";
  else if (a[1] == b[1]) cout << (mapa[a[0]] > mapa[b[0]] ? "YES" : "NO");
  else cout << "NO";

  return 0;
}