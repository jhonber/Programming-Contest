// http://codeforces.com/contest/518/problem/B

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

int main() {
  string s,t;
  cin >> s >> t;

  map<char,int> mapa,mapa2;
  for (int i = 0; i < t.size(); ++i) mapa[t[i]] ++;

  for (int i = 0; i < s.size(); ++i) mapa2[s[i]] ++;

  int a = 0, b = 0;
  foreach(x,mapa2) {
    char c = x->first;
    int necesito = x->second;
    if (islower(c)) {
      int hay = mapa[c];
      while (hay > 0 && necesito > 0) {
        necesito --;
        hay --;
        a ++;
      }
      mapa[c] = hay;
      mapa2[c] = necesito;
    }
    else {
      int hay = mapa[c];
      while (hay > 0 && necesito > 0) {
        necesito --;
        hay --;
        a ++;
      }
      mapa[c] = hay;
      mapa2[c] = necesito;
    }
  }

  foreach(x,mapa2) {
    char c = x->first;
    int necesito = x->second;
    if (necesito <= 0) continue;
    if (islower(c)) {
      int hay = mapa[toupper(c)];
      while (hay > 0 && necesito > 0) {
        necesito --;
        hay --;
        b ++;
      }
      mapa[c] = hay;
      mapa2[c] = necesito;
    }
    else {
      int hay = mapa[tolower(c)];
      while (hay > 0 && necesito > 0) {
        necesito --;
        hay --;
        b ++;
      }
      mapa[c] = hay;
      mapa2[c] = necesito;
    }
  }


  cout << a << " " << b;

  return 0;
}