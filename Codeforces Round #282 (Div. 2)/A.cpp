// http://codeforces.com/contest/495/problem/A

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

int main(){ __
  string n;
  cin >> n;

  char a = n[0];
  char b = n[1];

  map<char,int> mapa;
  mapa['0'] = 2;
  mapa['1'] = 7;
  mapa['2'] = 2;
  mapa['3'] = 3;
  mapa['4'] = 3;
  mapa['5'] = 4;
  mapa['6'] = 2;
  mapa['7'] = 5;
  mapa['8'] = 1;
  mapa['9'] = 2;

  cout << mapa[a] * mapa[b];

  return 0;
}